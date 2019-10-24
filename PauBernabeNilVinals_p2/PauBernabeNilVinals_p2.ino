/*
 * Pau Bernabé
 * Nil Viñals
 * p2
 * 
 */
unsigned char pinlect=2;
unsigned char pindig=31;
float valueV0;
long interval = 5000;      //INTERVAL DE 5s
long previousmillis = 0;
void setup() {
  Serial.begin(115200);
  pinMode(pindig, INPUT_PULLUP);
  
}

void loop() {
  unsigned int control;
  //Definim el nostre rang entre 0.5V i 2.0V.
  float vo_min = 0.5;
  float vo_max = 2.0;
  
  unsigned long currentMillis = millis();

  valueV0=analogRead(pinlect); //amb aquesta variable sabem el valor de v0
  control=digitalRead(pindig); //amb aquesta variable sabem si accionem el l'interruptor o no

  //Plotejarem vo_min i vo_max tota l'estona.
  Serial.println(vo_min);
  Serial.println(vo_max);

  //Si accionem l'interruptor deixarem de mostrar v0 durant un temps
  if (control == LOW){
    if (currentMillis - previousmillis > interval){
      //Quan ja hagi passat l'interval posem el control a high
      previousmillis = currentMillis;
      digitalWrite(control, HIGH);
    }
    
  }else{
    Serial.println(valueV0);
  }
  delay(100); //Fem la mesura cada 100ms com es demana
  

  
}
