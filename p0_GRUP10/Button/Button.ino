/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +3.3V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 modified Apr 27 2012
 by Robert Wessels
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = PUSH2;     //CONSTANT DEL BOTÓ QUE POLSAREM
const int ledPinG =  GREEN_LED;      // CONSTANTS DEL LEDS QUE UTILITZAREM
const int ledPinB =  BLUE_LED; 
const int ledPinR =  RED_LED; 
const int buttonPinBis = PUSH1; //CONSTANT DE L'ALTRE BOTÓ QUE PODREM POLSAR

long interval = 100;      //INTERVAL DE 100ms
long previousmillis = 0;
int buttonState = 0;         // VARIABLE D'ESTAT DEL BOTÓ INICIALMENT A 0
int buttonStateBis = 0;     //VARIABLE D'ESTAT DE L'ALTRE BOTÓ

void setup() {
  pinMode(ledPinG, OUTPUT);      //POSAREM ELS LEDS COM A SORTIDA
  pinMode(ledPinB, OUTPUT);
  pinMode(ledPinR, OUTPUT);
  pinMode(buttonPinBis, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);     //POSAREM EL BOTÓ COM A ENTRADA
}

void loop(){


  unsigned long currentMillis = millis();

  if(currentMillis - previousmillis > interval) { //CADA 100ms LLEGIREM L'ESTAT DELS BOTONS
    buttonState = digitalRead(buttonPin); //LLEGIREM L'ESTAT DELS BOTONS
    buttonStateBis =  digitalRead(buttonPinBis);
    previousmillis = currentMillis;
  }


  if ((buttonState == HIGH && buttonStateBis == LOW) || (buttonState == LOW && buttonStateBis == HIGH))  {  // SI APRETEM UN BOTÓ O L'ALTRE S'APAGARÀ EL LED VERD DEL RGB 
    digitalWrite(ledPinG, LOW);  
  }
  else if(buttonState == LOW && buttonStateBis == LOW){ //SI APRETEM ELS DOS BOTONS, S'ENCENDRAN ELS 3 LEDS DEL CONJUNT RGB
     digitalWrite(ledPinR, HIGH);
     digitalWrite(ledPinG, HIGH);
     digitalWrite(ledPinB, HIGH);
     
  }
  else {                  //ALTRAMENT EL LED VERD SERÀ L'ÚNIC QUE CONTINUARÀ ENCÈS
    digitalWrite(ledPinG, HIGH); 
    digitalWrite(ledPinR, LOW); 
    digitalWrite(ledPinB, LOW); 
  }
}
