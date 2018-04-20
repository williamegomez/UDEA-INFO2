
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()>0){
    char ByteLlegando = Serial.read(); 
    if(ByteLlegando == 'k'){
      digitalWrite(13, HIGH);
      Serial.print("12023020234"); // wait for a second
    }
  }
}

