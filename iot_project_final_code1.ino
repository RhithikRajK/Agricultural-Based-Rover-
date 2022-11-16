#include<Servo.h>
Servo servo01;
int servo01Pos=90;
int motor1_1=2;
int motor1_2=3;
int motor2_1=4;
int motor2_2=5;
int motore1=8;
int motore2=13;
int moisSensor=A0;
int gasSensor=A1;
int temp=A3;
int data=0;
void setup() {
  // put your setup code here, to run once:
  servo01.attach(11);
  Serial.begin(9600);
  //servo01Pos=90;
  servo01.write(servo01Pos);
  pinMode(motor1_1,OUTPUT);
  pinMode(motor1_2,OUTPUT);
  pinMode(motor2_1,OUTPUT);
  pinMode(motor2_2,OUTPUT);
  pinMode(motore1,OUTPUT);
  pinMode(motore2,OUTPUT);
  pinMode(moisSensor,INPUT);
  pinMode(gasSensor,INPUT);
  pinMode(temp,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    data=Serial.read();
  }
  while(data==1){
    if(Serial.available()>0){
      data=Serial.read();
    }
    digitalWrite(motore1,HIGH);
    digitalWrite(motore2,HIGH);
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);
  }
  while(data==2){
    if(Serial.available()>0){
      data=Serial.read();
    }
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
    digitalWrite(motor2_1,HIGH);
    digitalWrite(motor2_2,LOW);
  }
  while(data==3){
    if(Serial.available()>0){
      data=Serial.read();
    }
    digitalWrite(motor1_1,HIGH);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
  }
  while(data==4){
    if(Serial.available()>0){
      data=Serial.read();
    }
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,HIGH);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,HIGH);
  }
  while(data==7){
    if(Serial.available()>0){
      data=Serial.read();
    }
    servo01.write(++servo01Pos);
    //servo01Pos++;
  }
  while(data==8){
    if(Serial.available()>0){
      data=Serial.read();
    }
    servo01.write(--servo01Pos);
    //servo01Pos--;
  }
  while(data==0){
    if(Serial.available()>0){
      data=Serial.read();
    }
    digitalWrite(motor1_1,LOW);
    digitalWrite(motor1_2,LOW);
    digitalWrite(motor2_1,LOW);
    digitalWrite(motor2_2,LOW);
  }
  if(data==6)
  {
    float mois=0;
    float gas=0;
    float temp1=0;
    mois=analogRead(moisSensor);
    Serial.print("Moisture Sensor Value: ");
    Serial.print(mois);
    if(mois<300){
      Serial.print("\nSupply water to plants");
    }
    else{
      Serial.print("\nSufficient amount of water is there");
    }
    Serial.print("\nGas Sensor Value: ");
    gas=analogRead(gasSensor);
    Serial.print(gas);
    if(gas>400){
      Serial.println("\nSmoke is detected");
    }
    else{
      Serial.print("\nSmoke is not detected");
    }
    Serial.print("\nTemperature Sensor Value: ");
    temp1=analogRead(temp);
    temp1=(temp1*5000)/1024;
    temp1=temp1/10;
    temp1=(temp1-32.0)*(5.0/9.0);
    Serial.print(temp1);
    Serial.print("ºC\n");
    data=0;
  }
}
