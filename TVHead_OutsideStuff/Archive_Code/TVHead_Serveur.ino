#include "WiFi.h"
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include "SPIFFS.h"
//Hotspot telephone
const char* ssid = "TV-Head"; // Nom
const char* password = "12345678"; // mdp
//LED
const int pinLED = 23;
//etat initial du bouton sur la breadboard
int etatBouton = 0;

// instance du serveur asynchrone sur le port 80
AsyncWebServer monServeur(80);

void setup() {
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);
  
  // Moniteur série
  Serial.begin(115200);
  
  // lancer SPIFFS et informer s'il y a erreur
  if (!SPIFFS.begin(true)) {
   Serial.println("erreur avec SPIFFS");
  return;
  }
  
  // boucle de connexion au réseau Wi-Fi
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) { // Tant qu'on est pas connecté pour ne pas passer plus bas
    delay(1000);
    Serial.println("Connexion au réseau WiFi..");
  }
  
  // afficher adresse IP du ESP32
  Serial.println(WiFi.localIP()); // Peut seulement venir ici une fois le while plus haut fini 
  
  // écoute requête ("/" = page d'accueil)
  monServeur.on("/", HTTP_GET, [](AsyncWebServerRequest * request) { // Fonction anonyme avec parametre (request)
    //envoi du fichier HTML au client
    request->send(SPIFFS, "/index.html", String(), false); 
  });
  
  // écoute requête "/style.css" // Fonction anonyme avec parametre (request)
  monServeur.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    //envoi du fichier CSS au client
    request->send(SPIFFS, "/style.css", "text/css");
  });
  
 // écoute requête boutonON
 monServeur.on("/boutonON", HTTP_GET, [](AsyncWebServerRequest * request) {
  //on change l'etat du bouton
  etatBouton = 1;
  digitalWrite(pinLED, HIGH);
  //on l'affiche dans le moniteur serie
  Serial.println(etatBouton);
  //on renvoie aussi la page
  request->send(SPIFFS, "/index.html", String(), false);
 }); 

  // écoute requête boutonOFF
 monServeur.on("/boutonOFF", HTTP_GET, [](AsyncWebServerRequest * request) {
  //on change l'etat du bouton
  etatBouton = 0;
  digitalWrite(pinLED, LOW);
  //on l'affiche dans le moniteur serie
  Serial.println(etatBouton);
  //on renvoie aussi la page
  request->send(SPIFFS, "/index.html", String(), false);
 }); 
 
 // demarrer le serveur
 monServeur.begin();
}

void loop() {
}
