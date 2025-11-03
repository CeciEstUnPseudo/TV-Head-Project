#include "WiFi.h"
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include "SPIFFS.h"
#include <FastLED.h>
#include <SD.h>
#include <sd_defines.h>
#include <sd_diskio.h>

// Déclarations des fonctions
void startupServeur();
void startupLEDs();


// Data Pin Microprocesseur
const int pinData = 22;

// Info de la matrice
const int matrixLength = 17;
const int matrixHeight = 17;
const int nbLEDTotal = 289;
bool matrixFilLDirection = true;
CRGB maMatrixLEDs[nbLEDTotal]; // Tableau 1D pour FastLED

// Externes
extern void animationTick();


//Hotspot telephone
const char* ssid = "TV-Head"; // Nom
const char* password = "12345678"; // mdp

// INSTANCE DU SERVEUR ASYNCHRONE (Port 80)
AsyncWebServer monServeur(80);

void setup(){
  // Console
  Serial.begin(115200);
  //
  
  //startupLEDs(); // On setup les LEDs 
  startupServeur(); // On start le serveur

  FastLED.addLeds<WS2812B, pinData,GRB>(maMatrixLEDs, nbLEDTotal);
  FastLED.setBrightness(10);
}

  void loop() {
  tempsPasseeMillis = millis();
  animationTick();
  
  }