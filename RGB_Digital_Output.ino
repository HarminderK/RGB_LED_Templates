/*
 * Controlling a RGB Led with a Potentiometer (Digital)
 * 
 * 
 * 
 * 
 */
  


#define B 13 // Digital Blue Output
#define G 12 // Digital Green Output
#define R 11 // Digital Red Output
#define RGB A0 // Potentiometer


void setup() {
  // put your setup code here, to run once:
  pinMode(B, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(RGB, INPUT);

  Serial.begin(9600); //testing purposes
  
}

// Changing the colour of the RGB with the potentiometer
void loop() {
  int value = analogRead(RGB);
  if ( value <= 205) {
  digitalWrite(B, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(R, LOW);
  }

  if ( value >= 360 && value <= 460) {
  digitalWrite(B, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(R, LOW);
  }
  

  if ( value >= 460 && value <= 770) {
  digitalWrite(B, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(R, LOW);
  }

   if ( value >= 770 && value <= 870) {
  digitalWrite(B, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(R, HIGH);
  }

   if ( value >= 870 && value <= 1023) {
  digitalWrite(B, LOW);
  digitalWrite(G, LOW);
  digitalWrite(R, HIGH);
  }

 
  Serial.println(analogRead(RGB)); // testing purposes

}
