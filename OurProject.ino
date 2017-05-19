//We need to finish construction of our project!

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int inputPin = 3;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

int pos = 0;    // variable to store the servo position
int rled = 13;
int yled = 12;
int gled = 11;

// the setup routine runs once when you press reset:
void setup() {
// initialize the digital pin as an output.
pinMode(rled, OUTPUT);
pinMode(yled, OUTPUT);
pinMode(gled, OUTPUT);
myservo.attach(4);  // attaches the servo on pin 9 to the servo object
pinMode(inputPin, INPUT);     // declare sensor as input
}

// put your setup code here, to run once:
Serial.begin(9600);

// the loop routine runs over and over again forever:
void loop()
  for (pos = 0; pos <= 180; pos += 10) { // goes from 0 degrees to 180 degrees
    // in steps of 10 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

{  

  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    
digitalWrite(yled, HIGH); // turn the LED on (HIGH is the voltage level)
delay(1000);
// wait for a second
digitalWrite(yled, LOW); // turn the LED off by making the voltage LOW
delay(1000);
// wait for a second

digitalWrite(rled, HIGH); // turn the LED on (HIGH is the voltage level)
delay(1000);
// wait for a second
digitalWrite(rled, LOW); // turn the LED off by making the voltage LOW
delay(1000);
// wait for a second

    }


  } else {
  if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
      
  digitalWrite(gled, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);
  // wait for a second
  digitalWrite(gled, LOW); // turn the LED off by making the voltage LOW
  delay(1000);
  // wait for a second
      
    }

