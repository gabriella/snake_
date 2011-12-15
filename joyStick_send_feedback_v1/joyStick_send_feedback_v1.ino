

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;     // the number of the pushbutton pin
const int buttonPin3 = 4;     // the number of the pushbutton pin
const int buttonPin4 = 5;     // the number of the pushbutton pin
const int buttonPin5 = 6;     // the number of the pushbutton pin
const int buttonPin6 = 7;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:4
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState4 = 0;         // variable for reading the pushbutton status
int buttonState5 = 0;         // variable for reading the pushbutton status
int buttonState6 = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);     
    pinMode(buttonPin2, INPUT);     
      pinMode(buttonPin3, INPUT);     
        pinMode(buttonPin4, INPUT);     
         pinMode(buttonPin5, INPUT);     
        pinMode(buttonPin6, INPUT);     
}

void loop(){
  
  if(Serial.available()>0){
    byte incomingByte = Serial.read();
    if(incomingByte=='1'||incomingByte=='2'||incomingByte=='6'||incomingByte=='5'||incomingByte=='0')
    {
     digitalWrite(ledPin, HIGH); 
     delay(10);
     digitalWrite(ledPin, LOW);
     
    }
//    else {
//      digitalWrite(ledPin, LOW);
//    }
   /* if(incomingByte=='1'){
   digitalWrite(LED1, HIGH); 
  }
  else {digitalWrite(LED1, LOW);}
  
     if(incomingByte=='2'){
   digitalWrite(LED2, HIGH); 
  }
  else {digitalWrite(LED2, LOW);}
     if(incomingByte=='6'){
   digitalWrite(LED6, HIGH); 
  }
  else {digitalWrite(LED6, LOW);}
     if(incomingByte=='5'){
   digitalWrite(LED5, HIGH); 
  }
  else {digitalWrite(LED5, LOW);}
     if(incomingByte=='0'){
   digitalWrite(LED0, HIGH); 
  }
  else {digitalWrite(LED0, LOW);}
  */
    }
  
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
      buttonState3 = digitalRead(buttonPin3);
        buttonState4 = digitalRead(buttonPin4);
              buttonState5 = digitalRead(buttonPin5);
        buttonState6 = digitalRead(buttonPin6);

  // check if the pushbutton is pressed.

  if (buttonState1 == HIGH) {     

    Serial.print('1');
  }

if (buttonState2 == HIGH) { 
          Serial.print('2');}

if (buttonState4 == HIGH) { 
            Serial.print('4');
}

if (buttonState3 == HIGH) { 
            Serial.print('3');
}

if (buttonState5 == HIGH) { 
            Serial.print('5');
}

if (buttonState6 == HIGH) { 
            Serial.print('6');
}


delay(100);

  }
//    else {
//      digitalWrite(ledPin, LOW);
//    }WHY DOESNT THIS WORK
