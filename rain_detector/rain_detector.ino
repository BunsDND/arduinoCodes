#include <Servo.h>

Servo tap_servo;
int led = 8;
int tap_servo_pin = 5;

void setup() {
  Serial.begin(9600);
  tap_servo.attach(tap_servo_pin);

  pinMode(led, OUTPUT);
}

void loop() {
  int value = analogRead(A0);
  int value2 = analogRead(A2);

  // Print values for debugging
  Serial.print("Value 1: ");
  Serial.println(value);
  Serial.print("Value 2: ");
  Serial.println(value2);

  // Check conditions and control servo and LED
  if ((value >=5) && (value2 >= 8) ){
    digitalWrite(led, HIGH);
    tap_servo.write(0);  // Open position
    delay(1000);
  } else {
    digitalWrite(led, LOW);
    tap_servo.write(180);  // Closed position
    delay(1000);
  }
}
