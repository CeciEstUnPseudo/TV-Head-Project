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
const int pinData = 13;

// Info de la matrice
const int matrixLength = 17;
const int matrixHeight = 17;
const int nbLEDTotal = 289;
bool matrixFilLDirection = true;
CRGB maMatrixLEDs[nbLEDTotal]; // Tableau 1D pour FastLED

// Externes
extern void animationTick();
extern void gyroSetup();
extern void modeGyro();
extern void gyroDetection();


//Hotspot telephone
const char* ssid = "TV-Head"; // Nom
const char* password = "12345678"; // mdp

// INSTANCE DU SERVEUR ASYNCHRONE (Port 80)
AsyncWebServer monServeur(80);

void setup(){
  // Console
  Serial.begin(115200);
  //

  // Gyro stuff done in Gyro_Tilting.ino
  gyroSetup();

  //startupLEDs(); // On setup les LEDs 
  startupServeur(); // On start le serveur

  FastLED.addLeds<WS2812B, pinData,GRB>(maMatrixLEDs, nbLEDTotal);
  FastLED.setBrightness(10);

  modeGyro(); // PLACEHOLDER DU MODE DE BASE -- Right now testing the Gyro mode
}

  void loop() {
  tempsPasseeMillis = millis();
  animationTick();
  // Gyro stuff done in Gyro_Tilting.ino
  gyroDetection();

  
  }