#define trigPin1 9
#define echoPin1 8

#define trigPin2 10
#define echoPin2 11


long duration,distance,UltraSensor1,UltraSensor2;
char data;
String SerialData="";
void setup() {
Serial.begin(9600);

pinMode(trigPin1,OUTPUT);
pinMode(echoPin1,INPUT);

pinMode(trigPin2,OUTPUT);
pinMode(echoPin2,INPUT);


pinMode(20,OUTPUT);
pinMode(13,OUTPUT);
digitalWrite(20,HIGH);
digitalWrite(13,LOW);
  
  // put your setup code here, to run once:

pinMode(22,OUTPUT);// motor1
pinMode(24,OUTPUT);// motor1
pinMode(26,OUTPUT);// mot2
pinMode(28,OUTPUT);// mot2
pinMode(30,OUTPUT);// mot3
pinMode(32,OUTPUT);//mot3
pinMode(34,OUTPUT);//mot4
pinMode(36,OUTPUT);//mot4
pinMode(38,OUTPUT);//mot5
pinMode(40,OUTPUT);//mot5
pinMode(42,OUTPUT);//mot6
pinMode(44,OUTPUT);// mot6
}
void wait()
{
digitalWrite(22,LOW);//mot1fwd
digitalWrite(24,LOW);//mot1
digitalWrite(26,LOW);//mot2fwd
digitalWrite(28,LOW);//mot2
digitalWrite(30,LOW);//mot3fwd
digitalWrite(32,LOW);//mot3
digitalWrite(34,LOW);//mot4fwd
digitalWrite(36,LOW);//mot4
digitalWrite(38,LOW);//mot5fwd
digitalWrite(40,LOW);//mot5
digitalWrite(42,LOW);//mot6fwd
digitalWrite(44,LOW);//mot6
Serial.println("wait");
}
void forward()  // put your main code here, to run repeatedly:
{digitalWrite(22,HIGH);//mot1fwd
digitalWrite(24,LOW);//mot1
digitalWrite(26,HIGH);//mot2fwd
digitalWrite(28,LOW);//mot2
digitalWrite(30,HIGH);//mot3fwd
digitalWrite(32,LOW);//mot3
digitalWrite(34,HIGH);//mot4fwd
digitalWrite(36,LOW);//mot4
digitalWrite(38,HIGH);//mot5fwd
digitalWrite(40,LOW);//mot5
digitalWrite(42,HIGH);//mot6fwd
digitalWrite(44,LOW);//mot6
Serial.println("forward");
}
void backward()  // put your main code here, to run repeatedly:
{digitalWrite(22,LOW);//mot1fwd
digitalWrite(24,HIGH);//mot1
digitalWrite(26,LOW);//mot2fwd
digitalWrite(28,HIGH);//mot2
digitalWrite(30,LOW);//mot3fwd
digitalWrite(32,HIGH);//mot3
digitalWrite(34,LOW);//mot4fwd
digitalWrite(36,HIGH);//mot4
digitalWrite(38,LOW);//mot5fwd
digitalWrite(40,HIGH);//mot5
digitalWrite(42,LOW);//mot6fwd
digitalWrite(44,HIGH);//mot6
Serial.println("backward");
}
void left(){
   // put your main code here, to run repeatedly:
   digitalWrite(22,HIGH);//mot1fwd
digitalWrite(24,LOW);//mot1
digitalWrite(26,HIGH);//mot2fwd
digitalWrite(28,LOW);//mot2
digitalWrite(30,HIGH);//mot3fwd
digitalWrite(32,LOW);//mot3
digitalWrite(34,LOW);//mot4fwd
digitalWrite(36,HIGH);//mot4
digitalWrite(38,LOW);//mot5fwd
digitalWrite(40,HIGH);//mot5
digitalWrite(42,LOW);//mot6fwd
digitalWrite(44,HIGH);//mot6
Serial.println("left");
}
 void right()  // put your main code here, to run repeatedly:
{digitalWrite(22,LOW);//mot1fwd
digitalWrite(24,HIGH);//mot1
digitalWrite(26,LOW);//mot2fwd
digitalWrite(28,HIGH);//mot2
digitalWrite(30,LOW);//mot3fwd
digitalWrite(32,HIGH);//mot3
digitalWrite(34,HIGH);//mot4fwd
digitalWrite(36,LOW);//mot4
digitalWrite(38,HIGH);//mot5fwd
digitalWrite(40,LOW);//mot5
digitalWrite(42,HIGH);//mot6fwd
digitalWrite(44,LOW);//mot6
Serial.println("right");
}
void loop() {
SonarSensor(trigPin1,echoPin1);
UltraSensor1 = distance;
SonarSensor(trigPin2,echoPin2);
UltraSensor2 = distance;

while(Serial.available())
{
  delay(10);
  data=Serial.read();
  SerialData+=data;
}
//if(SerialData=="display distance")
//{
  Serial.println("distance measured by first sensor:");
  Serial.print(UltraSensor1);
  Serial.print(" cm");

  Serial.println("distance measured by second sensor:");
  Serial.print(UltraSensor2);
  Serial.print(" cm");
//}

SerialData="";
if(UltraSensor1 <=80 && UltraSensor2>=80)
{
left(); 
}

if(UltraSensor2 <=80 && UltraSensor1>=80)
{
right();
}
if(UltraSensor1 >=80 && UltraSensor2>=80)
{
forward(); 
}
if(UltraSensor1 <=80 && UltraSensor2<=80)
{
wait(); 
}
}
void SonarSensor(int trigPinSensor,int echoPinSensor)
{
  digitalWrite(trigPinSensor,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinSensor,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor,LOW);

  duration = pulseIn(echoPinSensor, HIGH);
  distance= (duration/2)/29.1; 
}
