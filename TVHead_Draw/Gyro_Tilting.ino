#include <Wire.h> // Allow i2C com. between senros & ESP32 (SDA + SCL lines)
#include <MPU6050.h> // Easy sensor functions

// Externes
extern void handleGyroAction(String gyroMode, String tilt);
extern String gyroMode;



// Variables
MPU6050 mpu; // MPU has a gyro, acceleration, & temperature module
String tilt = "normal";
const int tiltThreshold = 10000; // So I don't have to write 5000 a lot of times and I can select from here the tilt value threshold to send my signals


// Setup
void gyroSetup(){

  // Doing those in Main.ino
  Wire.begin(21, 22); // i2C com uses SDA and SCL. My ESP32's SCL is D21 and SDA D22
  mpu.initialize(); // Literally read the function, it does what it's named
  Serial.println("Gyro Initializations done ");

}


// Loop
void gyroDetection(){
  // Values coming from the MPU605

  int16_t accX, accY, accZ, gyroX, gyroY, gyroZ; // acc = acceleration. gyro = angular velocity

  mpu.getMotion6(&accX, &accY, &accZ, &gyroX, &gyroY, &gyroZ); // Could have made the values right into the getMotion6, fragmentation is better to learn for beginners tho
  // ---- We check the tilt via the acceleration (aka gravity is applied on what "side" of the MPU (if I understand correctly))

    // Logic || Only 1 "tilt" at a time (I don't want forward-left, for example. Only the one I did first, so on les a tous dans 1 seul "if else if else if")
      // Check if any of the 4 possibilities (right, left, forward, backward) else put tilt as ""

      // Right / Left -- Take priority over forward/backward (most prone to being mistaken as the other two)
      if (accX < -tiltThreshold){ // Means its tilted to the right
        if (tilt == "right") return;
        tilt = "right";
        handleGyroAction(gyroMode, tilt);
        Serial.println("Tilted RIGHT");
      } else if(accX > tiltThreshold) { // Means its tilted to the left
        if (tilt == "left") return;
        tilt = "left";
        handleGyroAction(gyroMode, tilt);
        Serial.println("Tilted LEFT");
      } 

      // Forward / Backward
      else if (accY < -tiltThreshold){ // Means its tilted forward
        if (tilt == "forward") return;
        tilt = "forward";
        handleGyroAction(gyroMode, tilt);
        Serial.println("Tilted FORWARD");
      } else if(accY > tiltThreshold){ // Means its tilted backward
        if (tilt == "backward") return;
        tilt = "backward";
        handleGyroAction(gyroMode, tilt);
        Serial.println("Tilted BACKWARD");

      } else if (tilt != "normal"){
        if (tilt == "normal") return;
        tilt = "normal";
        handleGyroAction(gyroMode, tilt);
        Serial.println("Tilt OFF (normal)");
      }

    
  // ----


  delay(50);
}