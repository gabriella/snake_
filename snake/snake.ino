
#include <Servo.h> 



Servo myservo1;  // create servo object to control a servo 
Servo myservo2;
Servo myservo3;
const int ledpin = 13;

void setup() 
{ 
  Serial.begin(9600);
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object 
  myservo3.attach(11);  // attaches the servo on pin 9 to the servo object 
  pinMode(ledpin, OUTPUT);

  myservo1.write(100);
  myservo2.write(100);
  myservo3.write(100);




} 

void loop() 
{ 
  if(Serial.available()>0){
    // Serial.println(Serial.read());
    digitalWrite(ledpin, HIGH);

    byte info=Serial.read();
    //Serial.println(info);
    if(info==49){

      myservo1.write(0);  
      myservo3.write(0);    
      Serial.print("forwards");

    }
    else if (info==50){
      myservo1.write(180); 
      myservo3.write(180);
      Serial.println("backwards");
    }
    else if(info==54)
    { Serial.println("right");
      myservo1.write(90);
      myservo3.write(90);

    }

    if(info==53){
      myservo2.write(0); 
      Serial.print("left");
    }
    else if(info==51||info==52)
    {
      myservo1.write(100); 
            myservo2.write(100); 
                  myservo3.write(100); 

      Serial.print('home');

    }
//    else{
//      myservo2.write(90);
//      Serial.print('0');
//    }

  }
  else{
    digitalWrite(ledpin, LOW);
  }
  delay(20);

}

//why is an led in pin 6 make 15 led stop 
//xbee has only 3V output why is it giving 5?
//have to look into why this is printing out the wrong values

