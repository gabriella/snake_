#include <Servo.h>

int servosPins[] = {2,3,4,5,6,7};
int servoValues[] = {90, 90, 90};
const int NUM_SERVOS = 3;
Servo servos[NUM_SERVOS];
const int FIRST_SERVO_PIN=2;

int nextServoValue = 0;


int currentServo = 0;

const int UPDATE_INTERVAL = 1000;

long lastUpdatedAt = 0;

void setup(){
  Serial.begin(9600);
  //setup all your servos;
  //for(int i=0;i<NUM_SERVOS;i++)
  //servos[i].attach(FIRST_SERVO_PIN +i);
  servos[0].attach(7);
    servos[1].attach(10);
      servos[2].attach(11);
  
  
  lastUpdatedAt = millis();
  
  Serial.println("starting");
}

void loop(){
  //Serial.println(millis());
  
  if(millis() - lastUpdatedAt  > UPDATE_INTERVAL){
    //Serial.println();
    //Serial.println();
    Serial.print("0: ");
    Serial.print(servoValues[0]);
        Serial.print("\t1: ");
    Serial.print(servoValues[1]);
        Serial.print("\t2: ");
    Serial.println(servoValues[2]);

  
    int myNewFirstValue = 90; //how ever you're calculating this
    //passDownServoValues(myNewFirstValue);
    // after hre your servoValues array is correct
    adjustServos();
    lastUpdatedAt = millis();
  }

}

void passDownServoValues(int firstValue){
  // {100, 50, 1, 23, 17, 100};
  // {firstVAlue, 100, 50, 1, 23, 17}
  
  
  // {90, 90, 90}
  // {0, 0, 90}
  for(int i = 2; i > 0; i--){//why cant write servoValues.length
    servoValues[i] = servoValues[i-1];
  }
  
  servoValues[0] = firstValue;
}

void adjustServos(){
  // update the current servo
  
  
  servos[currentServo].write(servoValues[currentServo]);
  
  currentServo++;
  if(currentServo > NUM_SERVOS-1){
    currentServo = 0;
  // passDownServoValues(myValue);why not
    Serial.println("passing down");
    passDownServoValues(nextServoValue);
    
    nextServoValue = nextServoValue + 30;
    if(nextServoValue > 130){
      nextServoValue = 0;
    }
    
  }
 
 // update all servos 
  //for(int i =0; i < NUM_SERVOS; i++){
  //  servos[i].write(servoValues[i]);
  //}
  //passDownServoValues(myValue);
}
