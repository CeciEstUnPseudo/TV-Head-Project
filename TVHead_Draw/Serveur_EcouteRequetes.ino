// Inclusion des déclarations depuis les autres fichiers
extern const int nbLEDTotal;
extern const int pinData;
extern CRGB maMatrixLEDs[];

extern void eteindre_matrix();

extern void dessin(String nomDessin);
extern void imageFixe(String nomDessin);
extern void animation(String nomAnimation, int qteFrames);
extern void gif(String nomAnimation, int qteFrames);
extern void stopAnimation();

String activeFace;

void startupServeur_requetes(){
  
    //////////////////
    // REQUETE Vide //
    //////////////////
  monServeur.on("/boutonOff", HTTP_GET, [](AsyncWebServerRequest * request) {
    stopAnimation(); // On arrête les animations si une joue
    imageFixe("Vide");
    activeFace = "fixe_Vide";
    //on l'affiche dans le moniteur serie
    Serial.println("Eteint matrice! | "+millis());
  // Réponse minimale (204 No Content) pour les appels fetch côté client
  request->send(204, "text/plain", "");
  }); 
    /////////////////
    /////////////////

    ////////////////////
    // REQUETE Canard //
    ////////////////////
  monServeur.on("/boutonCanard", HTTP_GET, [](AsyncWebServerRequest * request) {
    imageFixe("Canard");
    activeFace = "fixe_Canard";
    //on l'affiche dans le moniteur serie
    Serial.println("Canard! | "+millis());
  // Réponse minimale (204 No Content)
  request->send(204, "text/plain", "");
  }); 
    /////////////////
    /////////////////
     
    //////////////////////
    // REQUETE Papillon //
    //////////////////////
  monServeur.on("/boutonPapillon", HTTP_GET, [](AsyncWebServerRequest * request) {
    imageFixe("Papillon");
    activeFace = "fixe_Papillon";
    //on l'affiche dans le moniteur serie
    Serial.println("Papillon! | "+millis());
  // Réponse minimale (204 No Content)
  request->send(204, "text/plain", "");
  }); 
    /////////////////
    /////////////////
     
    ///////////////////////
    // REQUETE Thumbs up //
    ///////////////////////
  monServeur.on("/boutonThumbsUp", HTTP_GET, [](AsyncWebServerRequest * request) {
    imageFixe("ThumbsUp");
    activeFace = "fixe_ThumbsUp";
    //on l'affiche dans le moniteur serie
    Serial.println("Thumbs Up! | "+millis());
  // Réponse minimale (204 No Content)
  request->send(204, "text/plain", "");
  }); 
    /////////////////
    /////////////////
     
    ///////////////////////////////
    // REQUETE Thumbs up + Coeur //
    ///////////////////////////////
  monServeur.on("/boutonThumbsUpCoeur", HTTP_GET, [](AsyncWebServerRequest * request) {
    imageFixe("ThumbsUpWithHeart");
    activeFace = "fixe_ThumbsUpWithHeart";
    //on l'affiche dans le moniteur serie
    Serial.println("Thumbs Up Coeur! | "+millis());
  // Réponse minimale (204 No Content)
  request->send(204, "text/plain", "");
  }); 
    /////////////////
    /////////////////

    ///////////////////////////////////////////////
    // REQUETE ANIMATION INFINI (gif) Chargement //
    ///////////////////////////////////////////////
  monServeur.on("/boutonChargementInfini", HTTP_GET, [](AsyncWebServerRequest * request) {
    gif("chargement", 12);
    activeFace = "gif_chargement";
    //on l'affiche dans le moniteur serie
    Serial.println("Chargement infini! | "+millis());
  // Réponse minimale (204 No Content)
  request->send(204, "text/plain", "");
  }); 
    /////////////////
    /////////////////

    //////////////////////////////////
    // REQUETE ANIMATION Chargement //
    //////////////////////////////////
  monServeur.on("/boutonChargement", HTTP_GET, [](AsyncWebServerRequest * request) {
    animation("chargement", 12);
    activeFace = "anim_chargement";
    //on l'affiche dans le moniteur serie
    Serial.println("Chargement 1 fois! | "+millis());
  // Réponse minimale (204 No Content)
  request->send(204, "text/plain", "");
  }); 
    /////////////////
    /////////////////
     
}
