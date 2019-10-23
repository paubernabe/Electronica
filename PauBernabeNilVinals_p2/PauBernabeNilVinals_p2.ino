/*
 * Pau Bernabé
 * Nil Viñals
 * p2
 * 
 */
unsigned char pinlect=2;
unsigned char pindig=31;
int valueV0;
void setup() {
  Serial.begin(115200);
  pinMode(pindig, INPUT_PULLUP);
  
}

void loop() {
  unsigned int control=0;
  //Definim el nostre rang entre 0.5V i 2.0V.
  float vo_min = 0.5;
  float vo_max = 2.0;

  valueV0=analogRead(pinlect); //amb això sabem el valor de v0
  control=digitalRead(pindig); //amb això sabem si accionem el l'interruptor o no

  //Plotejarem vo_min i vo_max tota l'estona.
  Serial.println(vo_min);
  Serial.println(vo_max);

  //Si accionem l'interruptor deixarem de mostrar v0 durant un temps
  if (control == LOW){
    delay(5000);
    control == HIGH;
  }
  Serial.println(valueV0);
  delay(100); //Fem la mesura cada 100ms com es demana
  

  
}
