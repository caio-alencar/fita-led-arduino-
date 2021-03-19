#include <IRremote.h>
//DEC DO CONTROLE DA TV
#define onoff 551502015 
#define piscar 551516295 
#define piscar1 551518335
#define voltar 551494365 
#define pulsar 4294967295

//CONF DO IR 
int receiver = 2; 
uint32_t Previous; 
IRrecv irrecv(receiver); 
decode_results results; 

boolean estado_onoff = false; 
const int rgb_leds [] = {9,10,11};  //CONF LED RGB
const int leds [] = {3,4,5,6,7, 9, 10, 11}; //CONF TODOS LEDS 


void on_leds(){ //LIGAR LEDS NORMAIS 
  digitalWrite(7, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void dimm_all() { //LIGAR TODOS OS LEDS 
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

void off_all() { //DESLIGAR LEDS NORMAIS 
  for(int led = 0; led <=2; led++){ 
    analogWrite(rgb_leds[led],0); 
  }
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void pisca(){  //FUNÇÃO 1 PISCA DA ESQUERDA 
    digitalWrite(3, LOW);
    delay(100);
    digitalWrite(4, LOW);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(9,HIGH);
    //digitalWrite(10,HIGH);
    //digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
}

void pisca1(){  //PISCA DA DIREITA
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(9,LOW);
    // digitalWrite(10,LOW);
    //digitalWrite(11,LOW);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
    digitalWrite(4, LOW);
    delay(100);
    digitalWrite(3, LOW);
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(9,HIGH);
    // digitalWrite(10,HIGH);
    //digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(3, HIGH);
    delay(100);
}

void volta () { //VAI E VOLTA PISCANDO 
    digitalWrite(3, LOW);
    delay(150);
    digitalWrite(4, LOW);
    delay(150);
    digitalWrite(5, LOW);
    delay(150);
    digitalWrite(9,LOW);
   // digitalWrite(10,LOW);
    //digitalWrite(11,LOW);
    delay(150);
    digitalWrite(6, LOW);
    delay(150);
    digitalWrite(7, LOW);
    delay(150);
    digitalWrite(3, HIGH);
    delay(50);
    digitalWrite(4, HIGH);
    delay(50);
    digitalWrite(5, HIGH);
    delay(150);
    digitalWrite(9,HIGH);
    //digitalWrite(10,HIGH);
   // digitalWrite(11,HIGH);
    delay(150);
    digitalWrite(6, HIGH);
    delay(150);
    digitalWrite(7, HIGH);
    delay(150);

    digitalWrite(7, LOW);
    delay(150);
    digitalWrite(6, LOW);
    delay(150);
    digitalWrite(9,LOW);
    // digitalWrite(10,LOW);
    //digitalWrite(11,LOW);
    delay(150);
    digitalWrite(5, LOW);
    delay(150);
    digitalWrite(4, LOW);
    delay(150);
    digitalWrite(3, LOW);
    delay(150);
    digitalWrite(7, HIGH);
    delay(150);
    digitalWrite(6, HIGH);
    delay(150);
    digitalWrite(9,HIGH);
    // digitalWrite(10,HIGH);
    //digitalWrite(11,HIGH);
    delay(150);
    digitalWrite(5, HIGH);
    delay(150);
    digitalWrite(4, HIGH);
    delay(150);
    digitalWrite(3, HIGH);
    delay(150);

    
}

void pulsa () {
    digitalWrite(7, LOW);
    delay(100);
    digitalWrite(6, LOW);
    delay(100);
    digitalWrite(9,LOW);
    // digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    // digitalWrite(10,HIGH);
    //digitalWrite(11,LOW);
    delay(100);
    digitalWrite(5, LOW);
    delay(100);
    digitalWrite(4, LOW);
    delay(100);
    digitalWrite(3, LOW);
    delay(200);
    digitalWrite(3, HIGH);
    delay(100);
     digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(5, HIGH);
    delay(100);
   // digitalWrite(11,HIGH);
    delay(100);
     digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(7, HIGH);
    delay(100);
}

void setup() {
  Serial.begin(9600); 
  irrecv.enableIRIn(); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(11,OUTPUT); 
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}


void loop(){ 
  //INICIA IR 
  results.value = 0; 
  if(irrecv.decode(&results)){ 
    Serial.println(results.value,HEX);
    irrecv.resume(); 
  }

  if(results.value == onoff) { // LIGA LEDS 
    estado_onoff = !estado_onoff; 
    if(!estado_onoff){ 
      dimm_all();
       
    } 
  }


  else if (estado_onoff){ //DESLIGA LEDS 
    off_all(); 
  }

  if(results.value == piscar){ //PISCA DA ESQUERDA 
    for( int t = 0; t <= 5; t++){ 
      pisca(); 
    }   
  }

   if(results.value == piscar1){ //PISCA DA DIREITA 
    for( int t = 0; t <= 5; t++){ 
      pisca1(); 
    }
  }

   if(results.value == voltar){ //VOLTA 
    for( int t = 0; t <= 5; t++){ 
      volta(); 
    }  
   }

   

}
  


 
