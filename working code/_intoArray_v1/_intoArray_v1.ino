
#include <Servo.h> 
const int NBR_SERVOS= 30;  // the number of servos, up to 48 for Mega, 12 for other boards
const int FIRST_SERVO_PIN= 2;

int counter = 1;
Servo Servos[NBR_SERVOS] ; // max servos is 48 for mega, 12 for other boards


int pos [NBR_SERVOS];    // variable to store the servo position
int angle=100;
long lastMove = 0;
long lastPulse = 0;
int nextServo=0;

boolean firstContact=false;
 
void setup() 
{ 
  Serial.begin(9600);

  for( int i =0; i < NBR_SERVOS; i++)
    Servos[i].attach( FIRST_SERVO_PIN +i);//, 800, 2200);   
//Servos[i].write(pos[100]);

//  for( int i =0; i < NBR_SERVOS; i++){
//    Servos[i].write( pos[100]);//, 800, 2200);   
////Servos[i].write(pos[100]);
//}
}

 
void loop() 
{ 
  //sending one byte first to trigger serialEvent function in processing
//  if(!firstContact) {
//    Serial.println('Y');
//    firstContact=true;
//  }
    
  if (millis() - lastPulse > 15) {  // pulse servo every 20 ms
    pulseServo();
    lastPulse = millis();  // save the time when you last pulsed
  }

  // this if statement changes the angle every 0.5 seconds:
  
  if (millis() - lastMove > 100) {
    changeAngle();
    lastMove = millis(); 
  }
}


void changeAngle() {

   for(int i = 0; i<NBR_SERVOS; i++)  // goes from 0 degrees to 180 degrees 
  { pos[i]=angle;
  angle =angle+counter;
  if (angle>=130||angle<=60){
   counter*=-1; 
  }
  
//  if(angle<130){
//      angle-=counter;
//    }
// 
// else if(angle>60) {
//    angle+=counter  ;}
//    

    
  Serial.println(angle);
  }
  
 }
void pulseServo() {
  
   for( int i =0; i <NBR_SERVOS; i++) 
   {
    Servos[i].write(pos[i]);   
    //delay(15);                       // waits 15ms for the servo to reach the position 
  }
  }
 

