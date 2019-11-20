
long goal_time = 500; //  0.5 sec és el temps de referència
long previous_millis = 0;
long tone_time = 100;
float valueV0;
unsigned char pinlect = 2; //pin amb el que llegim v0
unsigned char pin_tone = 8; //pin pel buzzer
unsigned int note_1 = 440; //constant de la nota
unsigned int note_0 = 330;
void setup() {
    Serial.begin(115200);
    pinMode(pin_tone, OUTPUT);

}

void loop() {

  unsigned long currentMillis = millis();
  valueV0 = analogRead(pinlect); //llegirem el valor de V0 amb pin2

  if (valueV0 > 300){
    if(currentMillis - previous_millis > goal_time){

      previous_millis = currentMillis;
      Serial.println("0"); 
      tone(pin_tone, note_0, 5); //definim el pin, la nota i la duració
    }
    delay(tone_time);

  }else{
    Serial.println("1");
    tone(pin_tone, note_1, 5);
    
  }
  delay(tone_time);
}
