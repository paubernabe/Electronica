/* Blink without Delay
 
 Turns on and off a light emitting diode(LED) connected to a digital  
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.
 
 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.
 
 
 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 27 Apr 2012
 by Robert Wessels
 
 This example code is in the public domain.

 
 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

//const int ledPin =  GREEN_LED;      // the number of the LED pin
const int ledPin =  78; //CANVIEM LA CONSTANT GREEN_LED PER EL NUM 78 QUE REPRESENTA EL PIN DEL LED VERMELL

int ledState = LOW;             // L'ESTAT INICIAL DEL LED SERÀ APAGAT(LOW = 0 V)
long previousMillis = 0;        // UTILITZAREM AQUEST COM A BASE DEL COMPTADOR DE TEMPS PER MILISEGONS
int control = 0;

long interval2 = 1;
long interval = 10;           // DEFINIM EL TEMPS ENTRE QUE S'ENCÉN I S'APAGA

void setup() { //FUNCIÓ QUE UTILITZAREM PER LA CONFIGURACIÓ DELS PINS
  pinMode(ledPin, OUTPUT);  //EL PIN DEL LED EL DEFINIM COM A SORTIDA    
}

void loop() //ES CRIDA RECURSIVAMENT
{
  unsigned long currentMillis = millis(); //AQUESTA VARIABLE +=1 CADA MILISEGON
 
  if(currentMillis - previousMillis > interval) { //AQUI ENTRA QUAN SIGUI D'APAGAT A ENCÉS
    //SI HA PASSAT MÉS TEMPS DEL QUE HEM DEFINIT 
    previousMillis = currentMillis;   

    //CADA COP QUE HAGI PASSAT L'INTERVAL ES POSARÀ A L'ESTAT CONTRARI
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    digitalWrite(ledPin, ledState); //S'ECRIU AL PIN L'ESTAT AL QUE ESTÀ(ENCÉN EL PIN)

     control=0; //ENS INDICARÀ QUE EL LED ESTA ENCÉS
     
 }
  //
    else {
      if ((currentMillis - previousMillis > interval2) && (control==0)) {  //AQUI ES COMPLIRÀ EN EL TEMPS D'ENCÉS A APAGAT
        digitalWrite(ledPin, LOW); //S'ECRIU AL PIN L'ESTAT AL QUE ESTÀ(APAGA EL PIN)
        control=1; //ENS MARCARÀ QUE EL LED ESTÀ APAGAT
      }
    }
}
//EN CONCLUSIÓ EN CADA MÉS TEMPS ESTÀ APAGAT SIGNIFICARÀ UNA LLUM MENYS LLUMINOSA
