int led = 13;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  //%%%%%%%%%%%%%%%%%%%%%
  //Asincrona
  Serial.print("0");
  delay(100);
  Serial.print("1");
  delay(100);
  Serial.print("1");
  delay(100);
  Serial.print("1");
  delay(100);
  Serial.print("1");
  delay(100);
  //%%%%%%%%%%%%%%%%%%%%%
  //Sincrona
  if(Serial.available() > 0){
      if(Serial.read() == 'k'){
        Serial.println("010100010001100");
      }
  }
}
