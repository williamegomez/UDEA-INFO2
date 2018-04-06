
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()>0){
    
      char ByteLlegando = Serial.read(); 
    if(ByteLlegando == 'k')  
      Serial.println("00101010101111110000"); // wait for a second
  }
}
