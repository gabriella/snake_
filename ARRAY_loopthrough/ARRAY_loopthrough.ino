int servosPins[] = {2,3,4,5,6,7};
int servoValues[] = {90, 90, 90, 90, 90, 90};
Servo servos[];
const int NUM_SERVOS = 6;

int currentServo = 0;

const UPDATE_INTERVAL = 1000;

long lastUpdatedAt = 0;

void setup(){
  //setup all your servos;
  lastUpdatedAt = millis();
}

void loop(){
  if(lastUpdatedAt - millis() > UPDATE_INTERVAL){
    int myNewFirstValue = 7; //how ever you're calculating this
    //passDownServoValues(myNewFirstValue);
    // after hre your servoValues array is correct
    adjustServos();
    lastUpdatedAt = millis();
  }

}

void passDownServoValues(int firstValue){
  // {100, 50, 1, 23, 17, 100};
  // {firstVAlue, 100, 50, 1, 23, 17}
  
  for(int i = 1; i < servoValues.length; i++){
    servoValues[i] = servoValues[i-1];
  }
  
  servoValues[0] = firstValue;
}

void adjustServos(){
  // update the current servo
  
  servo[currentServo].write(servoValues[currentServo]);
  
  currentServo++;
  if(currentServo > NUM_SERVOS-1){
    currentServos = 0;
    passDownServoValues(myValue);
  }
 
 // update all servos 
  //for(int i =0; i < NUM_SERVOS; i++){
  //  servos[i].write(servoValues[i]);
  //}
  //passDownServoValues(myValue);
}
