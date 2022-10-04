#include <LiquidCrystal.h>

//******* CONFIGURACAO DO PROJETO *********
#define pinBotoes A0

#define pinRs 8
#define pinEn 9
#define pinD4 4
#define pinD5 5
#define pinD6 6
#define pinD7 7
#define pinBackLight 10
//*****************************************

#define btNENHUM 0
#define btSELECT 1
#define btLEFT   2
#define btUP     3
#define btDOWN   4
#define btRIGHT  5

#define tempoDebounce 50

unsigned long delayBotao;
int estadoBotaoAnt = btNENHUM;

//variaveis relogio
int segundos = 0, minutos = 0, horas = 0;


//Funções relogio
void mostraHoras();
void relogio();
void registrarHora();
void ajuste();


void estadoBotao(int botao);
void botaoApertado(int botao);
void botaoSolto(int botao);

LiquidCrystal lcd(pinRs, pinEn, pinD4, pinD5, pinD6, pinD7);

//Para o exemplo de uso
String descBotao[6] = {"", "Select", "Esquerda", "Abaixo", "Acima", "Direita"};
int contador = 0;

void setup() {
  pinMode(pinBackLight, OUTPUT);
  digitalWrite(pinBackLight, HIGH);

  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  int valBotoes = analogRead(pinBotoes);

  if ((valBotoes < 800) && (valBotoes >= 600)) {
     estadoBotao(btSELECT);
     
  } else if ((valBotoes < 600) && (valBotoes >= 400)) {
     estadoBotao(btLEFT);
     
  } else if ((valBotoes < 400) && (valBotoes >= 200)) {
     estadoBotao(btUP);
     
  } else if ((valBotoes < 200) && (valBotoes >= 60)) {
     estadoBotao(btDOWN);
     
  } else if  (valBotoes < 60) {
     estadoBotao(btRIGHT);
     
  } else {
     estadoBotao(btNENHUM);
  }
  
  relogio();
  registrarHora();
  mostraHoras();
  ajuste();

}

void estadoBotao(int botao) {
  //Quando um botao estiver apertado
  if (botao != btNENHUM) {
     Serial.println(botao);
  }

  //Quando o botao for apertado ou solto
  if ((millis() - delayBotao) > tempoDebounce) {
     if ((botao != btNENHUM) && (estadoBotaoAnt == btNENHUM) ) {
        botaoApertado(botao); 
        delayBotao = millis();
     }

     if ((botao == btNENHUM) && (estadoBotaoAnt != btNENHUM) ) {
        botaoSolto(estadoBotaoAnt); 
        delayBotao = millis();
     }
  }
  estadoBotaoAnt = botao;
}

void botaoApertado(int botao) {
  //Quando um botão for apertado

  //Para o exemplo de uso
  contador++;
  lcd.clear();
  lcd.print(descBotao[botao]);
  lcd.setCursor(14,0);
  lcd.print(contador);
  lcd.setCursor(0,1);
  lcd.print("apertado");
  lcd.clear();
}

void botaoSolto(int botao) {
  //Quando um botão for solto


  //Para o exemplo de uso
  lcd.clear();
  lcd.print(descBotao[botao]);
  lcd.setCursor(14,0);
  lcd.print(contador);
  lcd.setCursor(0,1);
  lcd.print("solto");
  lcd.clear();
}


void registrarHora(){
  int variavel = analogRead(A1);
  if(variavel<23){
     horas = variavel; //horas passa a ser o valor lido
  }
  lcd.print("          ");
  lcd.setCursor(0,4); 
  lcd.print(variavel);
  delay(400);
  lcd.clear();
}


void relogio(){
   segundos++;
  if(segundos > 59){
     segundos=0;
     minutos++;
  }
  
  if(minutos > 59){
     minutos=0;
     horas++;
  }
  
  if(horas>23){
     horas=0;
  }
}


void mostraHoras(){
  lcd.setCursor(0,0); 
  if(horas <= 9){lcd.print("0");}
  lcd.print(horas);
  lcd.print(":");
  if(minutos <= 9){lcd.print("0");}
  lcd.print(minutos);
  lcd.print(":");
  if(segundos <= 9){lcd.print("0");}
  lcd.print(segundos);

}


void ajuste(){
 
  if(estadoBotaoAnt==5){//btRIGHT
     estadoBotaoAnt=0;
     minutos++;
    if(minutos > 59){
       minutos=0;
    }
  }
  
  if(estadoBotaoAnt==3){ //btUP
     estadoBotaoAnt=0;
    horas=horas+1;
    if(horas>23){
      horas=0;
    }
  }
  
  
  if(estadoBotaoAnt==4){//btDOWN
     estadoBotaoAnt=0;
     minutos=minutos+10;
    if(minutos>59){
      minutos=0;
    }
  }
  
  if(estadoBotaoAnt==2){//btLEFT
     estadoBotaoAnt=0;
    horas = horas + 10;
    if(horas > 23){
       horas = 0;
    }
  }
}
