#include "Arduino.h"
#include "Flex.h"
#include "BTHC05.h"
#include <SoftwareSerial.h>


// Pin Definitions

#define FLEX_5V1_1_PIN_SIG  A2
#define FLEX_5V2_2_PIN_SIG  A3
#define FLEX_5V3_3_PIN_SIG  A4
#define BTHC05_PIN_TXD  A0
#define BTHC05_PIN_RXD  A1


// Global variables and defines

// object initialization
Flex flex_5v1_1(FLEX_5V1_1_PIN_SIG);
Flex flex_5v2_2(FLEX_5V2_2_PIN_SIG);
Flex flex_5v3_3(FLEX_5V3_3_PIN_SIG);


// define vars for testing menu
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 47000.0;  // resistor used to create a voltage divider
const float flatResistance = 25000.0; // resistance when flat
const float bendResistance = 100000.0;  // resistance at 90 deg
const int timeout = 10000;       //define timeout 
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
String bthc05Str = "";
BTHC05 bthc05(BTHC05_PIN_RXD,BTHC05_PIN_TXD);

SoftwareSerial BT(A0, A1);
void setup()
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    BT.begin(9600);
bthc05.begin(9600);
Serial.begin(9600);
    pinMode(FLEX_5V1_1_PIN_SIG, INPUT);
    pinMode(FLEX_5V2_2_PIN_SIG, INPUT);
    pinMode(FLEX_5V3_3_PIN_SIG, INPUT);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
   
    
   
    
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
   if (Serial.available()){
    
    // Flex Sensor 4.5'' #1 - Test Code
    // Read Flex sensor value.
    Serial.print(F("flex 1  is  "));
    int flex1 = analogRead(FLEX_5V1_1_PIN_SIG);
     Serial.println(flex1);
     float V1flex = flex1 * VCC / 1023.0;
  float R1flex = R_DIV * (VCC / V1flex - 1.0);

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle1 = map(R1flex, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend: " + String(angle1) + " degrees");
  Serial.println();
               delay(1000);

  
    
   
    // Flex Sensor 4.5'' #2 - Test Code
    // Read Flex sensor value.
    Serial.print(F("flex 2   is   ")); 
    int flex2 = analogRead(FLEX_5V2_2_PIN_SIG);
       Serial.println(flex2);
        float V2flex = flex2 * VCC / 1023.0;
  float R2flex = R_DIV * (VCC / V2flex - 1.0);

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle2 = map(R2flex, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend: " + String(angle2) + " degrees");
  Serial.println();
               delay(1000);
    
    
    // Flex Sensor 4.5'' #3 - Test Code
    // Read Flex sensor value.
    Serial.print(F("flex 3 is  ")); 
   int flex3 = analogRead(FLEX_5V3_3_PIN_SIG);
        Serial.println(flex3);
            Serial.println();
           float Vflex = flex3 * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();
               delay(1000);


  if((flex1>=620)&&(flex2>=411)&&(flex3>=410))
  {
    {Serial.println("hello");
   BT.println("hello");}
   delay(500);
  }
  else if((flex1>=630)&&(flex2>=445)&&(flex3>=434))
  {
    {Serial.println("thank you");
 BT.println("thank you");}
 delay(500);
  }
else if((flex1>=630)&&(flex2>=440)&&(flex3>=436))
  {
    {
      BT.println("A");
      Serial.println("A");
      delay(500);
    }
  }
  else if((flex1>=628)&&(flex2>=440)&&(flex3>=411))
  {
    {Serial.println("thank you");
     BT.println("thank you");
     delay(500);}
  }
  else if((flex1>=623)&&(flex2>=226)&&(flex3>=150))
  {
    {Serial.println("D");
    BT.println("D");
    delay(500);}
  }
else if((flex1>=582)&&(flex2>=317)&&(flex3>=289))
  {
    {Serial.println("o");
     BT.println("o");
     delay(500);}
  }
else if((flex1>=584)&&(flex2>=231)&&(flex3>=150))
  {
    {Serial.println("i love you");
     BT.println("i love you");
     delay(500);}
  }
  else if((flex1>=584)&&(flex2>=234)&&(flex3>=150))
  {
    {Serial.println("sorry");
    BT.println("sorry");
    delay(500);}
  }
  else 
  {
    { delay(5000);
      Serial.println("sorry not found");
    BT.println("please wait,checking");
     }
  }
}
}
