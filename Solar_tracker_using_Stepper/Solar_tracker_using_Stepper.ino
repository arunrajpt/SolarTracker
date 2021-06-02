#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <Stepper.h> // Include the header file

// change this to the number of steps on your motor
#define STEPS 40
const int buttonPin = 5; 
const int buttonPin1 = 4;
const int buttonPin2 = 6; 
int buttonState = 0;
int buttonState1 = 0;
int buttonState2 = 0;
// create an instance of the stepper class using the steps and pins
Stepper stepper(STEPS, 8, 10, 9, 11);

int val = 0,x=0;

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(500);
   pinMode(buttonPin, INPUT_PULLUP);
    pinMode(buttonPin1, INPUT_PULLUP);
 pinMode(buttonPin2, INPUT_PULLUP);
 lcd.begin(1, 2);
  lcd.print("Solar Tracker");
  delay(5000);
}

void loop() {
   
 int sensorValue = analogRead(A0);
 int sensorValue1 = analogRead(A1);
buttonState = digitalRead(buttonPin);
buttonState1 = digitalRead(buttonPin1);
buttonState2 = digitalRead(buttonPin2);
//Serial.print(sensorValue);
//Serial.print("---");
//Serial.println(sensorValue1);
delay(500);
if(buttonState2==LOW)
{
x=x+1;
delay(500);
        if(x>1)
        {
          x=0;
          lcd.clear();
          lcd.print("Manual Mod");
          delay(2000);
        }
  }

if(x==1)
{
  lcd.clear();
  lcd.print("Sensor Mod");
  
  if(sensorValue>900)
  {
    val=0;
    stepper.step(-50);
   
  }
  else if(sensorValue1>900)
  {
    stepper.step(50);
    
  }
}
else
{
   if (Serial.available()>0)
  {
    val = Serial.parseInt();
    stepper.step(val);
   // Serial.println(val); //for debugging
    
  }
 
  
if(buttonState==LOW)
{
 val=50;
stepper.step(val);
//Serial.println(val);
delay(300);
}

else if(buttonState1==LOW)
{
 val=-50;
stepper.step(val);
//Serial.println(val);
delay(300);
}
}

 int sensorValue3 = analogRead(A2);
  float voltage = sensorValue * (6.0 / 1023.0);
 // Serial.println(voltage);
  lcd.setCursor(0, 1);
  lcd.print(voltage);
   lcd.print(" V");
}
