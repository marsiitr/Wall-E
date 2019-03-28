#include "LedControl.h"
#include "Servo.h"

// pin 12  DataIn 
// pin 10  CLK 
// pin 11  LOAD 

#define ROBOT 2
LedControl lc=LedControl(12,10,11,ROBOT);

int initialpos=0;
const int eyeL = 0;  
const int eyeR = 1;  
byte left[8];


Servo S;

void setup() {
  S.attach(9);
  lc.shutdown(eyeL,false);
  lc.shutdown(eyeR,false);
  
  lc.setIntensity(eyeL,1);
  lc.setIntensity(eyeR,1);
  
  lc.clearDisplay(eyeL);
  lc.clearDisplay(eyeR);
  
  for(int row=0;row<8;row++) {
   lc.setRow(eyeL, row, 255);
   lc.setRow(eyeR, row, 255);
   
  }
  
  Serial.begin(9600);
}

void showNeutral() {
byte left[8] = {
B00000000,
B00111100,
B01000010,
B01011010,
B01011010,
B01000010,
B00111100,
B00000000};

  displayEmotion(left, left);
}

void showblink() {
  byte left[8]= {B11111111,B00111100,B01000010,B01011010,B01011010,B01000010,B11111111,B11111111};displayEmotion(left, left);}
void showblink_1() {  
 byte left[8]= {B00000000,B00000000,B00000000,B01111110,B11111111,B00000000,B00000000,B00000000};displayEmotion(left, left);}

void showblink_5() {   
  byte left[8]= {B11111111,B00111100,B01000010,B01011010,B01011010,B01000010,B11111111,B11111111};displayEmotion(left, left);} 


void displayEmotion(byte left[8], byte right[8]) {
  lc.clearDisplay(eyeL);
  lc.clearDisplay(eyeR);
  for(int row=0;row<8;row++) {
    lc.setRow(eyeL,row,left[row]);
    lc.setRow(eyeR,row,right[row]);
  }
}

void loop() {

  Serial.println("servo @  0");

  S.write(0);
    for (int i=0;i<90;i++){
      S.write(i);
      delay(15);
    }

    Serial.println("servo @  90");

   

  showblink();
  delay(500);

  showblink_1();
  delay(500);
 
  showblink_5();
  delay(500);

 

    

   for (int i=90;i<180;i++){
      S.write(i);
      delay(15);
    }
    Serial.println("servo @180");
   delay(500);

   
   for (int i=180;i>90;i--){
      S.write(i);
      delay(15);
    }

Serial.println("servo @90");
     showblink();
  delay(500);
 showblink_1();
  delay(500);
 
 
  showblink_5();
  delay(500);

Serial.println("servo @90");
for (int i=90;i<60;i=i-1){
      S.write(i);
      delay(150);
    }
  delay(1000);  
for (int i=60;i<30;i=i-1){
      S.write(i);
      delay(150);
    }

    delay(1000);  

    for (int i=30;i<0;i=i-1){
      S.write(i);
      delay(150);
    }
  
  
  
}
