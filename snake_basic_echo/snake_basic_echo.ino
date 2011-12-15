const int ledpin = 13;
void setup(){
 Serial.begin(9600);
 pinMode(ledpin, OUTPUT);
}
void loop(){
 if(Serial.available()>0){
   digitalWrite(ledpin, HIGH);
   byte info = Serial.read();
 //byte info= Serial.read();
// String info = Serial.read();
 // Serial.println(info);
 
 

 
if(info==49){
 
Serial.println("forwards"); 
}
else if(info==50){
 
 Serial.println("backwards");
}
else if(info==54){
 
 Serial.println("right");
}
else if(info==53){
 
 Serial.println("left");
}
 //Serial.flush();

 }
 else{digitalWrite(ledpin, LOW);
 }
// delay(10);

 } 


//if you use xbee shield - keep it clicked on USB cause you are using USB
