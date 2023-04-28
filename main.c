#include <Servo.h>
#define pinServo1 3
#define pinServo2 5
#define pinServo3 6

#define pinServo4 11
#define pinServo5 10

int ombro = 45;

int cotovelo = 90;

int pulso = 125;

int garra = 20;//idade




Servo servo1;
Servo servo2;
Servo servo3;

Servo servo4;
Servo servo5;

float g1 = 180.26;
int inc = 1;
float val1;
float val2;
float val3;

float val4;
float val5;

void setup()
{
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  
  servo4.attach(pinServo4);
  servo5.attach(pinServo5);
  
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  
  servo4.write(0);
  servo5.write(0);
  
  Serial.begin(9600);
}

void loop()
{
  if(inc ==1){
    g1 += inc;
    
    val1 =  map(g1, ombro, 1023, ombro, 227.33);
    val2 =  map(g1, cotovelo, 1023, cotovelo, 170.5);
    val3 =  map(g1, pulso, 1023, pulso, 142.08);
    
    val4 =  map(g1, garra, 1023, garra, 170.5);
    val5 =  map(g1, garra, 1023, garra, 142.08);
    
    servo1.write(val1);
    servo2.write(val2);
    servo3.write(val3);
    
    servo4.write(val2);
    servo5.write(val3);
    
    if(val1==80)
      inc = -1;
    Serial.print("val1: ");
    Serial.println(val1);
    Serial.print("val2: ");
    Serial.println(val2);
    Serial.print("val3: ");
    Serial.println(val3);
    
    Serial.print("val4: ");
    Serial.println(val4);
    Serial.print("val5: ");
    Serial.println(val5);
  }
  if(inc==-1){
    g1 += inc;
    
    val1 =  map(g1,0, 1023, 0, 227.33);
    val2 =  map(g1,0, 1023, 0, 170.5);
    val3 =  map(g1,0, 1023, 0, 142.08);
    
    val4 =  map(g1,0, 1023, 0, 170.5);
    val5 =  map(g1,0, 1023, 0, 142.08);
    
    servo1.write(val1);
    servo2.write(val2);
    servo3.write(val3);
    
    servo2.write(val4);
    servo3.write(val5);
    
    if(val1==40)
      inc = 1;
    Serial.print("val1: ");
    Serial.println(val1);
    Serial.print("val2: ");
    Serial.println(val2);
    Serial.print("val3: ");
    Serial.println(val3);
    
    Serial.print("val4: ");
    Serial.println(val4);
    Serial.print("val5: ");
    Serial.println(val5);
  }
}
