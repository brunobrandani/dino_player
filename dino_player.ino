#include <Servo.h>
#define SERVO 6

const int sensor_ldr = A5;
const int threashold = 340;
Servo s;
int pos;
int leitura;


void setup() {

  pinMode(sensor_ldr, INPUT);
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(10);

}

void loop() {
   
  leitura = analogRead(sensor_ldr);
  if(leitura > threashold){
    s.write(0);
    delay(300);
    s.write(10);
  }
  delay(10);
}
