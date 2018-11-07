/*
 * Author: Manash Kumar Mandal
 * Example For receiving data from SerialPort
 */

#define BAUD 9600

int newtime=0;
int oldtime=0;
int times=0;

int lnewtime=0;
int loldtime=0;
int ltimes=0;

int pulse;
char pxl[11];/*={1,1,0,0,1,0,1,1,0,1};*/

void setup() {
  attachInterrupt (0, cycletime, RISING);
  pinMode(4, OUTPUT);
}

void nextline(){
  Serial.begin(BAUD);
  Serial.print(8);
      delay(100);
  for(int i=0;i<10&&Serial.available();i++){
    delay(50);
    pxl[i]=Serial.read();
  }
  Serial.end();
}

void loop() {
 pulse=times/22;
for(int i=0;i<10;i++){
  if(pxl[i]==1){
    digitalWrite(4,HIGH);
    delayMicroseconds(pulse);
  }
  else{
  digitalWrite(4,LOW);
  delayMicroseconds(pulse);}
  }




lnewtime=millis();
ltimes=lnewtime-loldtime;
if(ltimes>=1000){
  loldtime=lnewtime;
  nextline();
  }
}
void cycletime(){
newtime=micros();
times=newtime-oldtime;
oldtime=newtime;
}

