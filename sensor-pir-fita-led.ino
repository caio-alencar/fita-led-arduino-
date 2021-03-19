#include <Servo.h>

#define pinPIR 13  

const int rgb_leds [] = {9,10,11}; 

void on_leds(){ 
  digitalWrite(7, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void off_all() { 
  for(int led = 0; led <=2; led++){ 
    analogWrite(rgb_leds[led],0); 
  }
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}


void dimm_all() {
  for ( int led = 0; led <= 2; led++ ) {
    if(led == 0 ){ 
          analogWrite( rgb_leds[ led ], 255 );
    }
    else if(led != 2 ) { 
      analogWrite( rgb_leds[ led ], 0 );
    }
  }
 on_leds(); 
}


void setup() {
  // put your setup code here, to run once:
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);

  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(11,OUTPUT); 
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  bool valorPIR = digitalRead(pinPIR); 
  if (valorPIR){
    Serial.println("detectado");
    dimm_all();
    delay(100000000);
   
  } else { 
    Serial.println("-----"); 
    off_all(); 
  }
}
