#include <FastLED.h>
const int nbLEDTotal = 289;
const int pinData = 22;

const int matrixLength = 17;
const int matrixHeight = 17;

bool matrixFilLDirection = true;

CRGB maMatrixLEDs[nbLEDTotal]; // Tableau 1D pour FastLED

void setup() {
  // put your setup code here, to run once:

  // Initialiser FastLED avec le tableau 1D
  FastLED.addLeds<WS2812B, pinData, GRB>(maMatrixLEDs, nbLEDTotal);


  
  FastLED.setBrightness(25);
  // dessiner_papillon();
  //dessiner_sourire();
  //dessiner_canard();
  // dessiner_thumbsUp();
  dessiner_thumbsUpWithHeart();

  FastLED.show();

  // Console
  Serial.begin(115200);
}

//////////////////////////////////////////////////////////////////
/////////////////////// FONCTIONS DE DESSIN  /////////////////////
//////////////////////////////////////////////////////////////////

void eteindre_matrix(){
   for (int i = 0; i < nbLEDTotal; i++) {
    maMatrixLEDs[i] = CRGB::Black;
  }
}


void dessiner_sourire(){
  eteindre_matrix();


  setLEDColor(2, 2, CRGB::Red);
  setLEDColor(2, 5, CRGB::Red);
  setLEDColor(4, 2, CRGB::Red);
  setLEDColor(4, 5, CRGB::Red);
  setLEDColor(5, 3, CRGB::Red);
  setLEDColor(5, 4, CRGB::Red);

  setLEDColor(10, 11, CRGB::Red);
  setLEDColor(10, 15, CRGB::Red);
  setLEDColor(13, 13, CRGB::Red);
  setLEDColor(14, 12, CRGB::Red);
  setLEDColor(14, 14, CRGB::Red);
  setLEDColor(15, 11, CRGB::Red);
  setLEDColor(15, 15, CRGB::Red);
}
void dessiner_papillon(){
  eteindre_matrix(); // Reinitialiser la matrice

  
  // Dessin

  // // Gris
  setLEDColor(0, 1, CRGB::Gray);
  setLEDColor(0, 15, CRGB::Gray);
  
  setLEDColor(1, 0, CRGB::Gray);
  setLEDColor(1, 2, CRGB::Gray);
  setLEDColor(1, 3, CRGB::Gray);
  setLEDColor(1, 13, CRGB::Gray);
  setLEDColor(1, 14, CRGB::Gray);
  setLEDColor(1, 16, CRGB::Gray);
  
  setLEDColor(2, 0, CRGB::Gray);
  setLEDColor(2, 4, CRGB::Gray);
  setLEDColor(2, 12, CRGB::Gray);
  setLEDColor(2, 16, CRGB::Gray);

  setLEDColor(3, 0, CRGB::Gray);
  setLEDColor(3, 5, CRGB::Gray);
  setLEDColor(3, 11, CRGB::Gray);
  setLEDColor(3, 16, CRGB::Gray);
  
  setLEDColor(4, 0, CRGB::Gray);
  setLEDColor(4, 6, CRGB::Gray);
  setLEDColor(4, 10, CRGB::Gray);
  setLEDColor(4, 16, CRGB::Gray);
  
  setLEDColor(5, 0, CRGB::Gray);
  setLEDColor(5, 7, CRGB::Gray);
  setLEDColor(5, 9, CRGB::Gray);
  setLEDColor(5, 16, CRGB::Gray);
  
  setLEDColor(6, 1, CRGB::Gray);
  setLEDColor(6, 8, CRGB::Gray);
  setLEDColor(6, 15, CRGB::Gray);

  setLEDColor(7, 1, CRGB::Gray);
  setLEDColor(7, 15, CRGB::Gray);

  setLEDColor(8, 1, CRGB::Gray);
  setLEDColor(8, 15, CRGB::Gray);

  setLEDColor(9, 2, CRGB::Gray);
  setLEDColor(9, 14, CRGB::Gray);

  setLEDColor(10, 3, CRGB::Gray);
  setLEDColor(10, 13, CRGB::Gray);
  setLEDColor(11, 2, CRGB::Gray);
  setLEDColor(11, 8, CRGB::Gray);
  setLEDColor(11, 14, CRGB::Gray);
  setLEDColor(12, 2, CRGB::Gray);
  setLEDColor(12, 8, CRGB::Gray);
  setLEDColor(12, 14, CRGB::Gray);
  setLEDColor(13, 2, CRGB::Gray);
  setLEDColor(13, 8, CRGB::Gray);
  setLEDColor(13, 14, CRGB::Gray);
  setLEDColor(14, 2, CRGB::Gray);
  setLEDColor(14, 7, CRGB::Gray);
  setLEDColor(14, 9, CRGB::Gray);
  setLEDColor(14, 14, CRGB::Gray);
  setLEDColor(15, 2, CRGB::Gray);
  setLEDColor(15, 4, CRGB::Gray);
  setLEDColor(15, 5, CRGB::Gray);
  setLEDColor(15, 6, CRGB::Gray);
  setLEDColor(15, 10, CRGB::Gray);
  setLEDColor(15, 11, CRGB::Gray);
  setLEDColor(15, 12, CRGB::Gray);
  setLEDColor(15, 14, CRGB::Gray);
  setLEDColor(16, 3, CRGB::Gray);
  setLEDColor(16, 13, CRGB::Gray);


  // // Mauves
  // 1 is 1 15. 2 is 1 2 3 13 14 15. 3 is 1 4 12 15. 4 is 1 5 11 15. 5 is 1 2 6 10 14 15. 6 is 2 7 9 14. 7 is 2 8 14. 8 is 2 14. 9 is 3 13. 10 is 4 8 12. 11 is 3 7 9 13. 12 is 3 7 9 13. 12 is 3 7 9 13. 13 is 3 7 9 13. 14 is 3 4 5 6 10 11 12 13. 15 is 3 13.
  setLEDColor(1, 1, CRGB::Turquoise);
  setLEDColor(1, 15, CRGB::Turquoise);
  setLEDColor(2, 1, CRGB::Turquoise);
  setLEDColor(2, 2, CRGB::Turquoise);
  setLEDColor(2, 3, CRGB::Turquoise);
  setLEDColor(3, 1, CRGB::Turquoise);
  setLEDColor(3, 4, CRGB::Turquoise);
  setLEDColor(3, 12, CRGB::Turquoise);
  setLEDColor(3, 15, CRGB::Turquoise);
  setLEDColor(4, 1, CRGB::Turquoise);
  setLEDColor(4, 5, CRGB::Turquoise);
  setLEDColor(4, 11, CRGB::Turquoise);
  setLEDColor(4, 15, CRGB::Turquoise);
  setLEDColor(5, 1, CRGB::Turquoise);
  setLEDColor(5, 2, CRGB::Turquoise);
  setLEDColor(5, 6, CRGB::Turquoise);
  setLEDColor(5, 10, CRGB::Turquoise);
  setLEDColor(5, 14, CRGB::Turquoise);
  setLEDColor(5, 15, CRGB::Turquoise);
  setLEDColor(6, 2, CRGB::Turquoise);
  setLEDColor(6, 7, CRGB::Turquoise);
  setLEDColor(6, 9, CRGB::Turquoise);
  setLEDColor(6, 14, CRGB::Turquoise);
  setLEDColor(7, 2, CRGB::Turquoise);
  setLEDColor(7, 8, CRGB::Turquoise);
  setLEDColor(7, 14, CRGB::Turquoise);
  setLEDColor(8, 2, CRGB::Turquoise);
  setLEDColor(8, 14, CRGB::Turquoise);
  setLEDColor(9, 3, CRGB::Turquoise);
  setLEDColor(9, 13, CRGB::Turquoise);
  setLEDColor(10, 4, CRGB::Turquoise);
  setLEDColor(10, 8, CRGB::Turquoise);
  setLEDColor(10, 12, CRGB::Turquoise);
  setLEDColor(11, 3, CRGB::Turquoise);
  setLEDColor(11, 7, CRGB::Turquoise);
  setLEDColor(11, 9, CRGB::Turquoise);
  setLEDColor(11, 13, CRGB::Turquoise);
  setLEDColor(12, 3, CRGB::Turquoise);
  setLEDColor(12, 7, CRGB::Turquoise);
  setLEDColor(12, 9, CRGB::Turquoise);
  setLEDColor(12, 13, CRGB::Turquoise);
  setLEDColor(13, 3, CRGB::Turquoise);
  setLEDColor(13, 7, CRGB::Turquoise);
  setLEDColor(13, 9, CRGB::Turquoise);
  setLEDColor(13, 13, CRGB::Turquoise);
  setLEDColor(14, 3, CRGB::Turquoise);
  setLEDColor(14, 4, CRGB::Turquoise);
  setLEDColor(14, 5, CRGB::Turquoise);
  setLEDColor(14, 6, CRGB::Turquoise);
  setLEDColor(14, 10, CRGB::Turquoise);
  setLEDColor(14, 11, CRGB::Turquoise);
  setLEDColor(14, 12, CRGB::Turquoise);
  setLEDColor(14, 13, CRGB::Turquoise);
  setLEDColor(15, 3, CRGB::Turquoise);
  setLEDColor(15, 13, CRGB::Turquoise);


  // // Roses

  // 3 is 2 3 13 14. 4 is 2 4 12 14. 5 is 3 5 11 13. 6 is 3 6 10 13. 7 is 3 7 9 13. 8 is 3 8 13. 9 is 4 8 12. 10 is 5 7 9 11. 11 is 4 6 10 12. 12 is 4 6 10 12. 13 is 4 5 6 10 11 12.
  setLEDColor(3, 2, CRGB::Cyan);
  setLEDColor(3, 3, CRGB::Cyan);
  setLEDColor(3, 13, CRGB::Cyan);
  setLEDColor(3, 14, CRGB::Cyan);
  setLEDColor(4, 2, CRGB::Cyan);
  setLEDColor(4, 4, CRGB::Cyan);
  setLEDColor(4, 12, CRGB::Cyan);
  setLEDColor(4, 14, CRGB::Cyan);
  setLEDColor(5, 3, CRGB::Cyan);
  setLEDColor(5, 5, CRGB::Cyan);
  setLEDColor(5, 11, CRGB::Cyan);
  setLEDColor(5, 13, CRGB::Cyan);
  setLEDColor(6, 3, CRGB::Cyan);
  setLEDColor(6, 6, CRGB::Cyan);
  setLEDColor(6, 10, CRGB::Cyan);
  setLEDColor(6, 13, CRGB::Cyan);
  setLEDColor(7, 3, CRGB::Cyan);
  setLEDColor(7, 7, CRGB::Cyan);
  setLEDColor(7, 9, CRGB::Cyan);
  setLEDColor(7, 13, CRGB::Cyan);
  setLEDColor(8, 3, CRGB::Cyan);
  setLEDColor(8, 8, CRGB::Cyan);
  setLEDColor(8, 13, CRGB::Cyan);
  setLEDColor(9, 4, CRGB::Cyan);
  setLEDColor(9, 8, CRGB::Cyan);
  setLEDColor(9, 12, CRGB::Cyan);
  setLEDColor(10, 5, CRGB::Cyan);
  setLEDColor(10, 7, CRGB::Cyan);
  setLEDColor(10, 9, CRGB::Cyan);
  setLEDColor(10, 11, CRGB::Cyan);
  setLEDColor(11, 4, CRGB::Cyan);
  setLEDColor(11, 6, CRGB::Cyan);
  setLEDColor(11, 10, CRGB::Cyan);
  setLEDColor(11, 12, CRGB::Cyan);
  setLEDColor(12, 4, CRGB::Cyan);
  setLEDColor(12, 6, CRGB::Cyan);
  setLEDColor(12, 10, CRGB::Cyan);
  setLEDColor(12, 12, CRGB::Cyan);
  setLEDColor(13, 4, CRGB::Cyan);
  setLEDColor(13, 5, CRGB::Cyan);
  setLEDColor(13, 6, CRGB::Cyan);
  setLEDColor(13, 10, CRGB::Cyan);
  setLEDColor(13, 11, CRGB::Cyan);
  setLEDColor(13, 12, CRGB::Cyan);

  // // Blanches (remis en Yellow)
  // 4 is 3 13. 5 is 4 12. 6 is 4 5 11 12. 7 is 4 5 6 10 11 12. 8 is 4 5 6 7 9 10 11 12. 9 is 5 6 7 9 10 11. 10 is 6 10. 11 is 5 11. 12 is 5 11.
  setLEDColor(4,3, CRGB::Yellow);
  setLEDColor(4,13, CRGB::Yellow);
  setLEDColor(5,4, CRGB::Yellow);
  setLEDColor(5,12, CRGB::Yellow);
  setLEDColor(6,4, CRGB::Yellow);
  setLEDColor(6,5, CRGB::Yellow);
  setLEDColor(6,11, CRGB::Yellow);
  setLEDColor(6,12, CRGB::Yellow);
  setLEDColor(7,4, CRGB::Yellow);
  setLEDColor(7,5, CRGB::Yellow);
  setLEDColor(7,6, CRGB::Yellow);
  setLEDColor(7,10, CRGB::Yellow);
  setLEDColor(7,11, CRGB::Yellow);
  setLEDColor(7,12, CRGB::Yellow);
  setLEDColor(8,4, CRGB::Yellow);
  setLEDColor(8,5, CRGB::Yellow);
  setLEDColor(8,6, CRGB::Yellow);
  setLEDColor(8,7, CRGB::Yellow);
  setLEDColor(8,9, CRGB::Yellow);
  setLEDColor(8,10, CRGB::Yellow);
  setLEDColor(8,11, CRGB::Yellow);
  setLEDColor(8,12, CRGB::Yellow);
  setLEDColor(9,5, CRGB::Yellow);
  setLEDColor(9,6, CRGB::Yellow);
  setLEDColor(9,7, CRGB::Yellow);
  setLEDColor(9,9, CRGB::Yellow);
  setLEDColor(9,10, CRGB::Yellow);
  setLEDColor(9,11, CRGB::Yellow);
  setLEDColor(10,6, CRGB::Yellow);
  setLEDColor(10,10, CRGB::Yellow);
  setLEDColor(11,5, CRGB::Yellow);
  setLEDColor(11,11, CRGB::Yellow);
  setLEDColor(12,5, CRGB::Yellow);
  setLEDColor(12,11, CRGB::Yellow);
  
}

void dessiner_canard(){

  // Jaune -> Orange (remplacé)
  // 3 est 4 à 7.  4 est 3 à 8. 5 est 4 6 7 8. 6 est 4 5 6 7 8. 7 est 5 6 7. 8 est 4 5 6 8 9 10 12. 9 est 3 à 10, 12. 10 est 2 3 4 5 7 8 9 11 12. 11 est 2 3 4 5 6 10 11 12. 12 est 2 à 12. 13 est 3 à 11. 14 est 4 à 10.
  setLEDColor(3, 4, CRGB::Orange);
  setLEDColor(3, 5, CRGB::Orange);
  setLEDColor(3, 6, CRGB::Orange);
  setLEDColor(3, 7, CRGB::Orange);
  setLEDColor(4, 3, CRGB::Orange);
  setLEDColor(4, 4, CRGB::Orange);
  setLEDColor(4, 5, CRGB::Orange);
  setLEDColor(4, 6, CRGB::Orange);
  setLEDColor(4, 7, CRGB::Orange);
  setLEDColor(4, 8, CRGB::Orange);
  setLEDColor(5, 4, CRGB::Orange);
  setLEDColor(5, 6, CRGB::Orange);
  setLEDColor(5, 7, CRGB::Orange);
  setLEDColor(5, 8, CRGB::Orange);
  setLEDColor(6, 4, CRGB::Orange);
  setLEDColor(6, 5, CRGB::Orange);
  setLEDColor(6, 6, CRGB::Orange);
  setLEDColor(6, 7, CRGB::Orange);
  setLEDColor(6, 8, CRGB::Orange);
  setLEDColor(7, 5, CRGB::Orange);
  setLEDColor(7, 6, CRGB::Orange);
  setLEDColor(7, 7, CRGB::Orange);
  setLEDColor(8, 4, CRGB::Orange);
  setLEDColor(8, 5, CRGB::Orange);
  setLEDColor(8, 6, CRGB::Orange);
  setLEDColor(8, 8, CRGB::Orange);
  setLEDColor(8, 9, CRGB::Orange);
  setLEDColor(8, 10, CRGB::Orange);
  setLEDColor(8, 12, CRGB::Orange);
  setLEDColor(9, 3, CRGB::Orange);
  setLEDColor(9, 4, CRGB::Orange);
  setLEDColor(9, 5, CRGB::Orange);
  setLEDColor(9, 6, CRGB::Orange);
  setLEDColor(9, 7, CRGB::Orange);
  setLEDColor(9, 8, CRGB::Orange);
  setLEDColor(9, 9, CRGB::Orange);
  setLEDColor(9, 10, CRGB::Orange);
  setLEDColor(9, 12, CRGB::Orange);
  setLEDColor(10, 2, CRGB::Orange);
  setLEDColor(10, 3, CRGB::Orange);
  setLEDColor(10, 4, CRGB::Orange);
  setLEDColor(10, 5, CRGB::Orange);
  setLEDColor(10, 7, CRGB::Orange);
  setLEDColor(10, 8, CRGB::Orange);
  setLEDColor(10, 9, CRGB::Orange);
  setLEDColor(10, 11, CRGB::Orange);
  setLEDColor(10, 12, CRGB::Orange);
  setLEDColor(11, 2, CRGB::Orange);
  setLEDColor(11, 3, CRGB::Orange);
  setLEDColor(11, 4, CRGB::Orange);
  setLEDColor(11, 5, CRGB::Orange);
  setLEDColor(11, 6, CRGB::Orange);
  setLEDColor(11, 10, CRGB::Orange);
  setLEDColor(11, 11, CRGB::Orange);
  setLEDColor(11, 12, CRGB::Orange);
  setLEDColor(12, 2, CRGB::Orange);
  setLEDColor(12, 3, CRGB::Orange);
  setLEDColor(12, 4, CRGB::Orange);
  setLEDColor(12, 5, CRGB::Orange);
  setLEDColor(12, 6, CRGB::Orange);
  setLEDColor(12, 7, CRGB::Orange);
  setLEDColor(12, 8, CRGB::Orange);
  setLEDColor(12, 9, CRGB::Orange);
  setLEDColor(12, 10, CRGB::Orange);
  setLEDColor(12, 11, CRGB::Orange);
  setLEDColor(12, 12, CRGB::Orange);
  setLEDColor(13, 3, CRGB::Orange);
  setLEDColor(13, 4, CRGB::Orange);
  setLEDColor(13, 5, CRGB::Orange);
  setLEDColor(13, 6, CRGB::Orange);
  setLEDColor(13, 7, CRGB::Orange);
  setLEDColor(13, 8, CRGB::Orange);
  setLEDColor(13, 9, CRGB::Orange);
  setLEDColor(13, 10, CRGB::Orange);
  setLEDColor(13, 11, CRGB::Orange);
  setLEDColor(14, 4, CRGB::Orange);
  setLEDColor(14, 5, CRGB::Orange);
  setLEDColor(14, 6, CRGB::Orange);
  setLEDColor(14, 7, CRGB::Orange);
  setLEDColor(14, 8, CRGB::Orange);
  setLEDColor(14, 9, CRGB::Orange);
  setLEDColor(14, 10, CRGB::Orange);
  

  // Orange -> Orange très foncé (remplacé)
  // 5 est 3. 6 est 1 2 3. 7 est 2 3 4.

  setLEDColor(5, 3, CRGB(139, 69, 19));  // Orange très foncé (SaddleBrown)
  setLEDColor(6, 1, CRGB(139, 69, 19));
  setLEDColor(6, 2, CRGB(139, 69, 19));
  setLEDColor(6, 3, CRGB(139, 69, 19));
  setLEDColor(7, 2, CRGB(139, 69, 19));
  setLEDColor(7, 3, CRGB(139, 69, 19));
  setLEDColor(7, 4, CRGB(139, 69, 19));


  // Une couleure foncée
  // 5 est 5.
  setLEDColor(5, 5, CRGB::DarkBlue);
}

void dessiner_thumbsUp(){
  eteindre_matrix();

  // Bleu
  // 2 is 10 11. 3 is 9 11. 4 is 9 11. 5 is 9 11. 6 is 8 11. 7 is 2 to 7, and 11 to 14. 8 is 2, 5, and 14. 9 is 2 to 5, and 14. 10 is 2 to 5, and 14. 11 is 2 to 5, and 14. 12 is 2 to 8, and 14. 13 is 2 to 5, and 9 to 13. 
  setLEDColor(2, 10, CRGB::Blue);
  setLEDColor(2, 11, CRGB::Blue);
  setLEDColor(3, 9, CRGB::Blue);
  setLEDColor(3, 11, CRGB::Blue);
  setLEDColor(4, 9, CRGB::Blue);
  setLEDColor(4, 11, CRGB::Blue);
  setLEDColor(5, 9, CRGB::Blue);
  setLEDColor(5, 11, CRGB::Blue);
  setLEDColor(6, 8, CRGB::Blue);
  setLEDColor(6, 11, CRGB::Blue);
  setLEDColor(7, 2, CRGB::Blue);
  setLEDColor(7, 3, CRGB::Blue);
  setLEDColor(7, 4, CRGB::Blue);
  setLEDColor(7, 5, CRGB::Blue);
  setLEDColor(7, 6, CRGB::Blue);
  setLEDColor(7, 11, CRGB::Blue);
  setLEDColor(7, 12, CRGB::Blue);
  setLEDColor(7, 13, CRGB::Blue);
  setLEDColor(7, 14, CRGB::Blue);
  setLEDColor(8, 2, CRGB::Blue);
  setLEDColor(8, 5, CRGB::Blue);
  setLEDColor(8, 14, CRGB::Blue);
  setLEDColor(9, 2, CRGB::Blue);
  setLEDColor(9, 3, CRGB::Blue);
  setLEDColor(9, 4, CRGB::Blue);
  setLEDColor(9, 5, CRGB::Blue);
  setLEDColor(9, 14, CRGB::Blue);
  setLEDColor(10, 2, CRGB::Blue);
  setLEDColor(10, 3, CRGB::Blue);
  setLEDColor(10, 4, CRGB::Blue);
  setLEDColor(10, 5, CRGB::Blue);
  setLEDColor(10, 14, CRGB::Blue);
  setLEDColor(11, 2, CRGB::Blue);
  setLEDColor(11, 3, CRGB::Blue);
  setLEDColor(11, 4, CRGB::Blue);
  setLEDColor(11, 5, CRGB::Blue);
  setLEDColor(11, 14, CRGB::Blue);
  setLEDColor(12, 2, CRGB::Blue);
  setLEDColor(12, 3, CRGB::Blue);
  setLEDColor(12, 4, CRGB::Blue);
  setLEDColor(12, 5, CRGB::Blue);
  setLEDColor(12, 6, CRGB::Blue);
  setLEDColor(12, 7, CRGB::Blue);
  setLEDColor(12, 8, CRGB::Blue);
  setLEDColor(12, 14, CRGB::Blue);
  setLEDColor(13, 2, CRGB::Blue);
  setLEDColor(13, 3, CRGB::Blue);
  setLEDColor(13, 4, CRGB::Blue);
  setLEDColor(13, 5, CRGB::Blue);
  setLEDColor(13, 9, CRGB::Blue);
  setLEDColor(13, 10, CRGB::Blue);
  setLEDColor(13, 11, CRGB::Blue);
  setLEDColor(13, 12, CRGB::Blue);
  setLEDColor(13, 13, CRGB::Blue);
  // White
  // 8 is 3 and 4. 
  setLEDColor(8, 3, CRGB::White);
  setLEDColor(8, 4, CRGB::White);
}

void dessiner_thumbsUpWithHeart(){
  eteindre_matrix();

  // Rouges (coeur)
  // 1 is 2 3 5 6. 2 is 1 to 7. 3 is 1 to 7. 4 is 1 to 7. 5 is 2 to 6. 6 is 3 4 5. 7 is 4.
  setLEDColor(1, 2, CRGB::Red);
  setLEDColor(1, 3, CRGB::Red);
  setLEDColor(1, 5, CRGB::Red);
  setLEDColor(1, 6, CRGB::Red);
  setLEDColor(2, 1, CRGB::Red);
  setLEDColor(2, 2, CRGB::Red);
  setLEDColor(2, 3, CRGB::Red);
  setLEDColor(2, 4, CRGB::Red);
  setLEDColor(2, 5, CRGB::Red);
  setLEDColor(2, 6, CRGB::Red);
  setLEDColor(2, 7, CRGB::Red);
  setLEDColor(3, 1, CRGB::Red);
  setLEDColor(3, 2, CRGB::Red);
  setLEDColor(3, 3, CRGB::Red);
  setLEDColor(3, 4, CRGB::Red);
  setLEDColor(3, 5, CRGB::Red);
  setLEDColor(3, 6, CRGB::Red);
  setLEDColor(3, 7, CRGB::Red);
  setLEDColor(4, 1, CRGB::Red);
  setLEDColor(4, 2, CRGB::Red);
  setLEDColor(4, 3, CRGB::Red);
  setLEDColor(4, 4, CRGB::Red);
  setLEDColor(4, 5, CRGB::Red);
  setLEDColor(4, 6, CRGB::Red);
  setLEDColor(4, 7, CRGB::Red);
  setLEDColor(5, 2, CRGB::Red);
  setLEDColor(5, 3, CRGB::Red);
  setLEDColor(5, 4, CRGB::Red);
  setLEDColor(5, 5, CRGB::Red);
  setLEDColor(5, 6, CRGB::Red);
  setLEDColor(6, 3, CRGB::Red);
  setLEDColor(6, 4, CRGB::Red);
  setLEDColor(6, 5, CRGB::Red);
  setLEDColor(7, 4, CRGB::Red);
  


  // Bleu (baissé de 2 sur l'axe Y)
  // 4 is 10 11. 5 is 9 11. 6 is 9 11. 7 is 9 11. 8 is 8 11. 9 is 2 to 7, and 11 to 14. 10 is 2, 5, and 14. 11 is 2 to 5, and 14. 12 is 2 to 5, and 14. 13 is 2 to 5, and 14. 14 is 2 to 8, and 14. 15 is 2 to 5, and 9 to 13. 
  setLEDColor(4, 10, CRGB::Blue);
  setLEDColor(4, 11, CRGB::Blue);
  setLEDColor(5, 9, CRGB::Blue);
  setLEDColor(5, 11, CRGB::Blue);
  setLEDColor(6, 9, CRGB::Blue);
  setLEDColor(6, 11, CRGB::Blue);
  setLEDColor(7, 9, CRGB::Blue);
  setLEDColor(7, 11, CRGB::Blue);
  setLEDColor(8, 8, CRGB::Blue);
  setLEDColor(8, 11, CRGB::Blue);
  setLEDColor(9, 2, CRGB::Blue);
  setLEDColor(9, 3, CRGB::Blue);
  setLEDColor(9, 4, CRGB::Blue);
  setLEDColor(9, 5, CRGB::Blue);
  setLEDColor(9, 6, CRGB::Blue);
  setLEDColor(9, 11, CRGB::Blue);
  setLEDColor(9, 12, CRGB::Blue);
  setLEDColor(9, 13, CRGB::Blue);
  setLEDColor(9, 14, CRGB::Blue);
  setLEDColor(10, 2, CRGB::Blue);
  setLEDColor(10, 5, CRGB::Blue);
  setLEDColor(10, 14, CRGB::Blue);
  setLEDColor(11, 2, CRGB::Blue);
  setLEDColor(11, 3, CRGB::Blue);
  setLEDColor(11, 4, CRGB::Blue);
  setLEDColor(11, 5, CRGB::Blue);
  setLEDColor(11, 14, CRGB::Blue);
  setLEDColor(12, 2, CRGB::Blue);
  setLEDColor(12, 3, CRGB::Blue);
  setLEDColor(12, 4, CRGB::Blue);
  setLEDColor(12, 5, CRGB::Blue);
  setLEDColor(12, 14, CRGB::Blue);
  setLEDColor(13, 2, CRGB::Blue);
  setLEDColor(13, 3, CRGB::Blue);
  setLEDColor(13, 4, CRGB::Blue);
  setLEDColor(13, 5, CRGB::Blue);
  setLEDColor(13, 14, CRGB::Blue);
  setLEDColor(14, 2, CRGB::Blue);
  setLEDColor(14, 3, CRGB::Blue);
  setLEDColor(14, 4, CRGB::Blue);
  setLEDColor(14, 5, CRGB::Blue);
  setLEDColor(14, 6, CRGB::Blue);
  setLEDColor(14, 7, CRGB::Blue);
  setLEDColor(14, 8, CRGB::Blue);
  setLEDColor(14, 14, CRGB::Blue);
  setLEDColor(15, 2, CRGB::Blue);
  setLEDColor(15, 3, CRGB::Blue);
  setLEDColor(15, 4, CRGB::Blue);
  setLEDColor(15, 5, CRGB::Blue);
  setLEDColor(15, 9, CRGB::Blue);
  setLEDColor(15, 10, CRGB::Blue);
  setLEDColor(15, 11, CRGB::Blue);
  setLEDColor(15, 12, CRGB::Blue);
  setLEDColor(15, 13, CRGB::Blue);
  // White (baissé de 2 sur l'axe Y)
  // 10 is 3 and 4. 
  setLEDColor(10, 3, CRGB::White);
  setLEDColor(10, 4, CRGB::White);
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
///////// FONCTIONS D'UTILISATION / PARCOURS DE LA MATRIX  ///////
//////////////////////////////////////////////////////////////////

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


void loop() {
  // put your main code here, to run repeatedly:

  // Afficher la matrix dans la console série
  for (int i = 0; i < matrixHeight; i++) {
    for (int j = 0; j < matrixLength; j++) {
      // Calculer et afficher la position numérique de chaque LED
      int position = getLED(i, j); // j=x, i=y (avec pattern serpentin)
      Serial.print(position);
      Serial.print("\t"); // Utiliser une tabulation pour l'alignement
    }
    Serial.println(); // Nouvelle ligne à la fin de chaque rangée
  }
  Serial.println("--------------------"); // Séparateur
  delay(2000); // Attendre 2 secondes avant le prochain affichage

}