import processing.serial.*;

Serial myPort;
int valueToSend = 0;
long lastMove=0;
    
int num_servos = 30;    
int[] servoValues = new int [num_servos];
    
void setup() {
  myPort = new Serial(this, Serial.list()[0], 9600);
  for (int i = 0; i < num_servos; i++) {
      servoValues[i] = 0;
  }
}

void draw() {
   if (millis() - lastMove > 1000) {
    updateAngle();   
    lastMove = millis();    
   }
}

void updateAngle() {
   for (int i = 0; i < num_servos-1; i++) {
      servoValues[i] = int(random(50, 160));
   }
}

void sendAngle() {
  // declare an array of bytes with one element per servo
  byte out[] = new byte[num_servos];
  // for each servo value
  for(int i=0; i < num_servos-1; i++){
    //    turn that value into a byte
    out[i] = byte(servoValues[i]); // 0-180
  }
  myPort.write(out);
}


void serialEvent(Serial myPort) {
  //serialEvent is called automatically when new data has been received
  //so hadnshake means that arduino sends out a byte after it has received data
  //this byte triggers serialEvent
  //
 print((char)myPort.read()); 
 sendAngle();
}

