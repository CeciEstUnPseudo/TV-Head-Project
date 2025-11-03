  #include <FastLED.h>
  #include "SPIFFS.h"

  extern const int nbLEDTotal;
  extern const int pinData;
  extern const int matrixLength;
  extern const int matrixHeight;
  extern CRGB maMatrixLEDs[];

  // Déclarations des fonctions
  CRGB stringToCRGB(String couleur);
  void setLEDColor(int y, int x, CRGB couleurVoulue);
  CRGB getLEDColor(int y, int x);
  int getLED(int y, int x);

  // Variables pour gérer les dessins et animations
  String dernierDessinVoulu = "Canard"; // Valeur par défaut au démarrage
  String retourApresAnimation; // Dessin à revenir après l'animation one-time
  String typeDeRetour = "";
  int retourQteFrames;

  // Controles et settings des animations
  bool animPlaying = false;
  String animName = "";
  int animFrameIndex = 0;
  int animQteFrames = 0;
  int animStopped = false;
  
  // Info pour timers (en ms)
  unsigned long tempsPasseeMillis;
  unsigned long animPrevMillis = 0;
  unsigned long animInterval = 100; // en ms 50-100 est bon (100 est assez bon, 50 un peu vite)
  bool gifInfini = false;


  void startupLEDs(){
    // Si on veut une image par défaut
    // Dessins manuels
    // dessiner_papillon();
    // dessiner_sourire();
    // dessiner_canard();
    // dessiner_thumbsUp();
    // dessiner_thumbsUpCoeur();
    // FastLED.show(); // Utiliser show après un dessin
  }

  //////////////////////////////////////////////////////////////////
  /////////////////////// FONCTIONS DE DESSIN  /////////////////////
  //////////////////////////////////////////////////////////////////


  // Bouton off 
  void eteindre_matrix(){
    typeDeRetour = "";
    FastLED.clear();
    Serial.println("Eteindre la matrice | " + millis());
  }

  // Fonction de dessin (called par boutons, prends d'un CSV)

    void dessin(String nomDessin){
        dernierDessinVoulu = nomDessin;
      
      // nomDessin = le dessin à faire
      Serial.println("Dessin de " + nomDessin + " | " + millis());

  // Aller chercher le bon .csv dans SPIFFS (dossier data/csv)
  File fichierDessin = SPIFFS.open("/csv/" + nomDessin + ".csv", "r");
      if(!fichierDessin){ // En gros si le fichierDessin n'existe pas
        return;
      }

      // Mettre chaque segment du .csv (entre les ;) dans un tableau
      String couleurs[nbLEDTotal]; // Le tableau qui fait la mm taille que le nmb de pixels (comme maMatrixLEDs)
      int couleursIndex = 0; // Remettre index = 0 pour chaque dessin
      
      while(fichierDessin.available() && couleursIndex < nbLEDTotal-1){ // -1 pour éviter un overflow car 0-288 = 289 éléments mais 0-289 = 290 éléments
        String segmentCSV = fichierDessin.readStringUntil(';'); // Lire jusqu'au prochain ';', ce qui va aussi skip les ;
        couleurs[couleursIndex] = segmentCSV; // Mettre le segment (XXX,XXX,XXX) dans le tableau
        couleursIndex++; // Incrémenter l'index
      }

      
      fichierDessin.close(); // Fermer le fichier après l'avoir lu

      Serial.println("Fin de l'assemblage du tableau de couleurs, on va appliquer les couleurs: " + nomDessin + " | " + millis());

      // Parcourir les LEDs et leur donner la couleur demandée qui vient du tableau créé avec les segments du .csv
      for (int i = 0; i < nbLEDTotal; i++) { // Pour chaque LED aka la taille de maMatrixLEDs et la taille de couleurs
        if (couleurs[i] != "" && nomDessin == dernierDessinVoulu) { // Si la couleur n'est pas vide
          
          // Convertir en coordonnées pour matrice
          int y = i / matrixLength;  // Ligne // Info 1/3 pour colorier un pixel
          int x = i % matrixLength;  // Colonne // Info 2/3 pour colorier un pixel

          CRGB couleurCRGB = stringToCRGB(couleurs[i]); // Convertir la couleur de string à CRGB // Info 3/3 pour colorier un pixel
                  setLEDColor(y, x, couleurCRGB); // Appliquer couleur sur le pixel
          
        }
      }
      if (nomDessin == dernierDessinVoulu){
        Serial.println("Fin des setLEDColor du dessin + dernier dessin voulu, on affiche: " + nomDessin + " | " + millis());
        FastLED.show(); // Allumer les LEDs
      }

  }

  // Commence l'animation
  void startAnimation(String name, int qteFrames, unsigned long intervalMs, bool infinite) {
    animName = name;
    animQteFrames = qteFrames;
    animInterval = intervalMs;
    gifInfini = infinite;
    animFrameIndex = 0;

    // Dessiner le premier dessin directement
    Serial.println("Start animation:" + animName + " with " + String(animQteFrames) + " frames, interval: " + String(animInterval) + "ms, infinite: " + String(gifInfini) + "|" + millis());


    dessin(animName + String(animFrameIndex));

    animPrevMillis = millis();
    animPlaying = true;
  }

  // Arrêter l'animation
  void stopAnimation() {
    Serial.println("Stop animation! | " + millis());
    animPlaying = false;
    animStopped = true;
    animPrevMillis = 0;
    animFrameIndex = 0;
    FastLED.clear();
  }

    void imageFixe(String nomDessin){
    stopAnimation(); // On arrête les animations si une joue
    retourApresAnimation = nomDessin; // On garde le dernier dessin pour y revenir après l'animation one-time
    typeDeRetour = "imageFixe";
    dessin(nomDessin);    
  }

  void animation(String nomAnimation, int qteFrames) {
    startAnimation(nomAnimation, qteFrames, animInterval, false);
  }

  void gif(String nomAnimation, int qteFrames) { // Seule différence: on joue en boucle donc gifInfini = true
    retourApresAnimation = nomAnimation; // On garde le dernier dessin pour y revenir après l'animation one-time
    typeDeRetour = "gif";
    retourQteFrames = qteFrames;
    startAnimation(nomAnimation, qteFrames, animInterval, true);
  }

  // Faire avancer l'animation de frame en frame
  void animationTick() {
    if (!animPlaying) return; // Si pas d'animation en cours, sortir

    unsigned long tempsPasseeMillis = millis(); // Obtenir le temps actuel
    if (tempsPasseeMillis - animPrevMillis >= animInterval && animPlaying) { //Si interval écoulé
      animPrevMillis = tempsPasseeMillis; // Mettre à jour le temps du dernier tick
      Serial.println("Tick animation! | " + millis());

      
      animFrameIndex++; // Index
      if (animFrameIndex >= animQteFrames) { // Si on a dépassé le nombre de frames
        if (gifInfini) { // Si on doit jouer en boule (gif infini)
          animFrameIndex = 0;
        } else { // Sinon, arrêter l'animation one-time et retourner au truc (imageFixe ou gif) d'avant
          stopAnimation();
          if (typeDeRetour == ""){ // Si on avant rien avant l'animation (one-time est la 1ere chose qu'on joue)
            eteindre_matrix();
          } else if (typeDeRetour == "gif") {
            gif(retourApresAnimation, retourQteFrames); // Revenir au gif de avant l'animation one-time
          } else { // Else on retourne a une image
            dessin(retourApresAnimation); // Revenir au dessin de avant l'animation one-time
          }
          return; 
        }
      }

      // Vu qu'on sort si: pas d'animation ou si on a fini l'animation, ici on peut dessiner la frame en toute sécurité
      Serial.println("Commence dessin animation depuis animationTick! | " + millis());
      if (animPlaying){
        dessin(animName + String(animFrameIndex)); // Dessine la frame
      }
    }
  }


  ////////////////////////////////////////////////////////////////////////////////
  //////////////// FONCTION DE CONVERSION COULEUR STRING -> CRGB  ////////////////
  ////////////////////////////////////////////////////////////////////////////////

  CRGB stringToCRGB(String couleur) { 
    couleur.trim(); // Enlever les espaces au cas où
    
    // Format RGB numérique (ex: "255,0,0" ou "255,128,64")
    if (couleur.indexOf(',') != -1) {  // Si on trouve une virgule, c'est le bon format
      int premiereVirgule = couleur.indexOf(','); // Trouver la position de la première virgule
      int deuxiemeVirgule = couleur.indexOf(',', premiereVirgule + 1); // Trouver la position de la deuxième virgule
      
      if (premiereVirgule != -1 && deuxiemeVirgule != -1) { // Si on a bien trouvé les deux virgules
        int r = couleur.substring(0, premiereVirgule).toInt(); // Convertir la partie avant la première virgule en int
        int g = couleur.substring(premiereVirgule + 1, deuxiemeVirgule).toInt(); // Convertir la partie entre les deux virgules en int
        int b = couleur.substring(deuxiemeVirgule + 1).toInt(); // Convertir la partie après la deuxième virgule en int
        
        // S'assurer que les valeurs sont entre 0-255
        r = constrain(r, 0, 255); 
        g = constrain(g, 0, 255);
        b = constrain(b, 0, 255);
        
        return CRGB(r, g, b);
      } else {
        // Si format non-valide, retourne noir (éteint)
        return CRGB::Black;
      }
    
    } else {
        // Si format non-valide, retourne noir (éteint)
        return CRGB::Black;
    }
  }

  //////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////////////////////////////////
  //////////////// FONCTIONS D'UTILISATION / PARCOURS DE LA MATRICE  ////////////////
  ///////////////////////////////////////////////////////////////////////////////////

  // Fonction pour convertir coordonnées 2D vers index 1D (En gros pour piocher dans le tableau 1D comme si c'était une matrice 2D)

  int getLED(int y, int x) {
    int led = y * matrixLength + x; // Calcul de l'index 1D (en gros où se trouve la LED dans le tableau 1D)

    // Inverser les rangées impaires pour le pattern serpentin
    if (y % 2 == 1) { // Si y est impair (1, 3, 5, ...) alors on inverse la rangée 
      led = y * matrixLength + (matrixLength - 1 - x);
    }
    return led;
  }

  // Fonction pour définir une LED à une position (y,x) (utile pour allumer une LED spécifique (x,y) à une couleur donnée)
  void setLEDColor(int y, int x, CRGB couleurVoulue) {
    if (x >= 0 && x < matrixLength && y >= 0 && y < matrixHeight) {
      maMatrixLEDs[getLED(y, x)] = couleurVoulue;
    }
  }

  // Fonction pour obtenir la couleur d'une LED à une position (y,x) (utile pour lire la couleur d'une LED spécifique, sinon retourne noir (éteint))
  CRGB getLEDColor(int y, int x) {
    if (x >= 0 && x < matrixLength && y >= 0 && y < matrixHeight) {
      return maMatrixLEDs[getLED(y, x)];
    }
    return CRGB::Black;
  }

  //////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////