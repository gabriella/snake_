// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // create servo object to control a servo 
Servo myservo3;  // create servo object to control a servo 
Servo myservo4;  // create servo object to control a servo 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;
int val1 = 100;    // variable to read the value from the analog pin 
int val2= 100;    // variable to read the value from the analog pin 
 
void setup() 
{ Serial.begin(9600);
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
    myservo2.attach(10);  // attaches the servo on pin 9 to the servo object 
      myservo3.attach(11);  // attaches the servo on pin 9 to the servo object 
        myservo4.attach(12);  // attaches the servo on pin 9 to the servo object 
  
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val1 = map(val, 0, 1023, 60, 140);     // scale it to use it with the servo (value between 0 and 180) 
    val2 = map(val, 0, 1023, 140,60);     // scale it to use it with the servo (value between 0 and 180) 
  myservo1.write(val1);                  // sets the servo position according to the scaled value 
    myservo3.write(val1);                  // sets the servo position according to the scaled value 
      myservo2.write(val2);                  // sets the servo position according to the scaled value 
        myservo4.write(val2);                  // sets the servo position according to the scaled value 
  //Serial.println(val1);
  delay(15);                           // waits for the servo to get there 
} 

//first in line: 136 to 60
//second 130 to 60
//33 to 130
//42 to 120
//hook up ground in series
