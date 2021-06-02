#define left1 6
#define left2 7
#define right1 4
#define right2 5


int LDRValue1 = 0;
int LDRValue2 = 0;

const int analogInPin = A0; 
const int analogInPin1 = A2;
const int analogInPin2 = A5;  

int sensorValue = 0;        
int sensorValue1 = 0;
int sensorValue2 = 0;        
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(left1,OUTPUT);
pinMode(left2,OUTPUT);
pinMode(right1,OUTPUT);
pinMode(right2,OUTPUT);
}

void loop() {
    sensorValue = analogRead(analogInPin);
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  delay(500);
  //Serial.print(sensorValue);
  //Serial.print("-----------");
  //Serial.print(sensorValue1);
  //Serial.print("-----------");
  //Serial.println(sensorValue2);
//Serial.println();  
  if(sensorValue<=100)
  {
  //Serial.print("1");
  digitalWrite(left1,HIGH);
  digitalWrite(left2,LOW);
   digitalWrite(right1,HIGH);
  digitalWrite(right2,LOW);
  delay(100);
  digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
   digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  delay(100);
    }
   
  if(sensorValue1<=100)
  {
  //Serial.print("0");
  digitalWrite(left1,LOW);
  digitalWrite(left2,HIGH);
   digitalWrite(right1,LOW);
  digitalWrite(right2,HIGH);
  delay(100);
  digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
   digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  delay(100);
   }
  else 
  {
    
      digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
   digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  }
  if(sensorValue2<=125)
  {
   Serial.print("1");
    delay(4000);
  }
}
