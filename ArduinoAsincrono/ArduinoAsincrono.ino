int led = 13;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  //%%%%%%%%%%%%%%%%%%%%%
  //Asincrona
  Serial.print("-");
  Serial.print("10101010101011101010101010101010101");
  Serial.print("-");
  
  delay(100);
}
