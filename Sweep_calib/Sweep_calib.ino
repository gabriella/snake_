// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(7);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop(){ 

if(Serial.available()>0){
  digitalWrite(13, HIGH);
  byte info = Serial.read();
  Serial.println(info);
  if(info=='1'){

 
  for(pos = 60; pos < 130; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  }
  else if(info=='2'){
    
    for(pos = 130; pos>=61; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  }
  

} 
  else if(Serial.available()<0)
    {
      myservo.write(pos);
  }
  Serial.println(pos);
  

}
