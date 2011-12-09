
#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
 Servo myservo2;
 Servo myservo3;
 const int ledpin = 5;
 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo1.attach(2);  // attaches the servo on pin 9 to the servo object 
  myservo2.attach(3);  // attaches the servo on pin 9 to the servo object 
  myservo3.attach(4);  // attaches the servo on pin 9 to the servo object 
  pinMode(ledpin, OUTPUT);
} 
 
void loop() 
{ 
  if(Serial.available()>0){
 // Serial.println(Serial.read());
 digitalWrite(ledpin, HIGH);
  
byte info=Serial.read();
//Serial.println(info);
  if(info=='1'){
   
     myservo1.write(0);  
myservo3.write(0);    
Serial.print('1');

  }
  else if (info=='2'){
   myservo1.write(180); 
   myservo3.write(180);
   Serial.print('2');
  }
  else
{myservo1.write(90);
myservo3.write(90);

}
  
 if(info=='6'){
  myservo2.write(0); 
  Serial.print('6');
 }
 else if(info=='5')
 {
  myservo2.write(180); 
  Serial.print('5');
   
 }
 else{myservo2.write(90);
 Serial.print('0');
}

  }
    else{digitalWrite(ledpin, LOW);}
  delay(20);

}

//why is an led in pin 6 make 15 led stop 
//xbee has only 3V output why is it giving 5?
//have to look into why this is printing out the wrong values
