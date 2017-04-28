#include <Servo.h>
#include <SharpIR.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

#define ir A0
#define model 20150
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            (working distance range according to the datasheets)

SharpIR SharpIR(ir, model);

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

}

int dis=SharpIR.distance();  // this returns the distance to the object you're measuring

Serial.print("Mean distance: ");  // returns it to the serial monitor
Serial.println(dis);

// the loop routine runs over and over again forever:
void loop() {
digitalWrite(gled, HIGH); // turn the LED on (HIGH is the voltage level)
delay(4000);
// wait for a second
digitalWrite(gled, LOW); // turn the LED off by making the voltage LOW
delay(1000);
// wait for a second

digitalWrite(yled, HIGH); // turn the LED on (HIGH is the voltage level)
delay(1000);
// wait for a second
digitalWrite(yled, LOW); // turn the LED off by making the voltage LOW
delay(1000);
// wait for a second

digitalWrite(rled, HIGH); // turn the LED on (HIGH is the voltage level)
delay(4000);
// wait for a second
digitalWrite(rled, LOW); // turn the LED off by making the voltage LOW
delay(1000);
// wait for a second


}
