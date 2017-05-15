/*
 * Analog output of RGB Led using Potentiometer
 * 
 *  Notes: 
 *  Each analog output needs an output value greater 
 *  than ~135 for the individual colour to turn on.
 *  
 *  There doesn't seem to be a "max" value for the analog output,
 *  using 255 because of the colour graph.
 */


#define POT A0
#define BLUE A1
#define GREEN A2
#define RED A3
#define MAX 255
#define MIN 0

void setup() {
  // put your setup code here, to run once:
  pinMode(POT, INPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  
  analogWrite(BLUE, MIN);
  analogWrite(GREEN, MIN);
  analogWrite(RED, MIN);

  Serial.begin(9600); //testing purposes
  
}

void loop() {
int value = analogRead(POT);
Serial.println(analogRead(POT));

if(value <= MAX && value >= MIN) 
{
  analogWrite(BLUE, value);
}

if(value <= MAX*2 && value > MAX) 
{
  analogWrite(BLUE, 2*MAX - value);
  analogWrite(GREEN, value - MAX);
}

if(value <= MAX*3 && value > MAX*2) 
{
  analogWrite(GREEN, 3*MAX - value);
  analogWrite(RED, value - 2*MAX);
}

if(value <= 1020 && value > MAX*3) 
{
  analogWrite(BLUE, value - 3*MAX);
  analogWrite(GREEN, value - 3*MAX);
  analogWrite(RED, value - 3*MAX);
}

if(value <= 1023 && value > 1020) 
{
  analogWrite(BLUE, MAX);
  analogWrite(GREEN, MAX);
  analogWrite(RED, MAX);
}


}
