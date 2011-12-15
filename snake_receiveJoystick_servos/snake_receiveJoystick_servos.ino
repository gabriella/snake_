
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

      myservo1.write(60);  
      myservo2.write(60); 
         myservo3.write(60);   
      Serial.println("forwards");

    }
    else if (info==50){
      myservo1.write(100); 
            myservo2.write(100); 
      myservo3.write(100);
      Serial.println("backwards");
    }
    else if(info==54)
    { Serial.println("right");
      myservo1.write(120);
            myservo2.write(120);
      myservo3.write(120);

    }

    if(info==53){
      myservo1.write(40); 
            myservo2.write(40); 
                  myservo3.write(40); 
      Serial.println("left");
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

