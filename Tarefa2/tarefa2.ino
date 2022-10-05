//Amélia, Geovana, Gustavo, Maria

#define pinMot1A 13 // a 
#define pinMot2A 12 // a 
#define pinMot1B 11 // b
#define pinMot2B 10 // b

int valorSensor = 0;

void setup()
{
  Serial.begin (9600);
  pinMode(A0,INPUT);
  pinMode(pinMot1A,OUTPUT);
  pinMode(pinMot1B,OUTPUT);
  pinMode(pinMot2A,OUTPUT);
  pinMode(pinMot2B,OUTPUT);
}


void loop()
{
  valorSensor = analogRead(A0);
  Serial.print(valorSensor);
  Serial.println('\t');
  //delay(1000); // Wait for 1000 millisecond(s)

  if (valorSensor < 200){
      avanca();
  }else if(valorSensor >=200 && valorSensor < 400){
      retrocede();
  }else if(valorSensor >=400 && valorSensor < 600){
      moveDir();
  }else{ //valorSensor>600
     moveEsq();
  } 
  //delay(1000); // Wait for 1000 millisecond(s)
}


void retrocede(){
  digitalWrite(pinMot1A,HIGH);
  digitalWrite(pinMot2A,LOW);
  
  digitalWrite(pinMot1B,HIGH);
  digitalWrite(pinMot2B,LOW);
  delay(1000);
}

void avanca(){
  digitalWrite(pinMot1A,LOW);
  digitalWrite(pinMot2A,HIGH);
  
  digitalWrite(pinMot1B,LOW);
  digitalWrite(pinMot2B,HIGH);
  delay(1000);
}

void moveEsq(){
  digitalWrite(pinMot1A,HIGH);
  digitalWrite(pinMot2A,LOW);

  digitalWrite(pinMot1B,LOW);
  digitalWrite(pinMot2B,HIGH);
  delay(1000);
}

void moveDir(){
  digitalWrite(pinMot1A,LOW);
  digitalWrite(pinMot2A,HIGH);

  digitalWrite(pinMot1B,HIGH);
  digitalWrite(pinMot2B,LOW);
  delay(1000);
}
