#incloude <servo.h>
servo moto;
int tr=10,ec=9;
int x=0;
int D=0;
void setup() {
  moto.attach(3);
  pinMode(tr,OUTPUT);
  pinMode(ec,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(tr,LOW);
  delayMicroseconds(2);
  
   digitalWrite(tr,HIGH);
  delayMicroseconds(10);
  digitalWrite(tr,LOW);
  
  x=pulseIn(ec,HIGH);
  D=x*0.034/2;
  serial.print("Distance");
  serial.printIn(D);
  if (D<300 && D>200) {
    moto.write(135);
  }
  else if (D<199 && D>100) {
    moto.write(90);
  }
  else if (D<99 && D>0) {
     moto.write(45);
  }
  
}
    