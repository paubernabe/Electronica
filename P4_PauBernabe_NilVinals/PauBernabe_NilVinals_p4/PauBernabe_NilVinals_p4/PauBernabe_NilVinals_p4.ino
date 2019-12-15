//****************************
//***   P4 - Transistors   ***
//*** Tocar notes musicals ***
//****************************

//Fitxer que relaciona text amb les freqüències de notes musicals
#include "notes_frequencies.h"

//Partituras
//Partitura 01
//Notes amb silencis (): (C:Do, D:Re, E:Mi, F:Fa, G: Sol, A:La, B:Si)
//unsigned int notes[] = {NA4,ND4,NF4,NG4,NA4,ND4,NF4,NG4,NE4,NG4,NC4,NF4,NE4,NG4,NC4,NF4,NE4,ND4,ND4};
//Duracio notes normalitzades a t0
//unsigned int duracio_notes[] = {6,6,1,1,4,4,1,1,12,6,6,1,1,4,6,1,1,4,6};
//Partitura 02
unsigned int notes[] = {ND3,ND3,ND3,NG3,ND4,NC4,NB3,NA3,NG4,ND4,NC4,NB3,NA3,NG4,ND4,NC4,NB3,NC4,NA3};
unsigned int duracio_notes[] = {2,2,2,8,8,2,2,2,8,4,2,2,2,8,4,2,2,2,4};

unsigned int t0=100;  //Base de temps (1) per la duració de les notes (en mil·lisegons)

unsigned int button = 31; //pin pel botó
int sizeofNotes = sizeof(notes);
int currentNote = 0;
int button_state;
unsigned char buzzer = 40; //pin pel buzzer

void setup() {
    Serial.begin(115200);
    pinMode(button, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
}


void loop() {
   button_state = digitalRead(button);
   if(currentNote < sizeofNotes){
      if(button == LOW){
        tone(buzzer, notes[currentNote], duracio_notes[currentNote]);
        currentNote++;
      
      }
      delay(t0);

   }else{
      currentNote = 0;
   }
   delay(t0);
}
