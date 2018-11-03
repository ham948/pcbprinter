/*
 * Author: Manash Kumar Mandal
 * Example For receiving data from SerialPort
 */

#define BAUD 9600
#define led 13


String receivedString;
volatile int newtime=0;
volatile int oldtime=0;
volatile int times=0;
int pulse;
int a=0;

void setup() {
  Serial.begin(BAUD);
  pinMode(led, OUTPUT);
  attachInterrupt (0, cycletime, RISING);
  pinMode(4, OUTPUT);
}

void loop() {
for(int n=0;n!=20;n++){
pulse=times/20;
digitalWrite(4,HIGH);
delayMicroseconds(pulse);
digitalWrite(4,LOW);
delayMicroseconds(pulse);}
}
void cycletime(){
newtime=micros();
times=newtime-oldtime;
oldtime=newtime;
}

