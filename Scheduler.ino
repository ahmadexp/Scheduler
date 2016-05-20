#include <Scheduler.h>
#include "Command.hpp"

#define LEDA 38
#define LEDB 37
#define LEDC 39
#define LEDD 40

int CURRENT_SPEED = 1000;
int led_a_state, led_b_state, led_c_state, led_d_state;
unsigned long current_time;
String time_stamp = "";

void setup(){
  Serial.begin(9600);
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDC, OUTPUT);
  pinMode(LEDD, OUTPUT);
}

void loop(){
  if (Serial.available()) {
    char c = Serial.read();
    led_a_state = digitalRead(LEDA);
    led_b_state = digitalRead(LEDB);
    led_c_state = digitalRead(LEDC);
    led_d_state = digitalRead(LEDD);
    current_time = millis();
    time_stamp = "[";
    time_stamp += current_time;
    time_stamp += "ms]: ";
    if (c == 'a' || c == 'A') {
      digitalWrite(LEDA, (led_a_state == HIGH ? LOW : HIGH) );
      Serial.print(time_stamp);
      Serial.println(led_a_state == HIGH ? "Turn off A" : "Turn on A");
    } else if (c == 'b' || c == 'B') {
      digitalWrite(LEDB, (led_b_state == HIGH ? LOW : HIGH) );
      Serial.print(time_stamp);
      Serial.println(led_b_state == HIGH ? "Turn off B" : "Turn on B");
    } else if (c == 'c' || c == 'C') {
      digitalWrite(LEDC, (led_c_state == HIGH ? LOW : HIGH) );
      Serial.print(time_stamp);
      Serial.println(led_c_state == HIGH ? "Turn off C" : "Turn on C");
    } else if (c == 'd' || c == 'D') {
      digitalWrite(LEDD, (led_d_state == HIGH ? LOW : HIGH) );
      Serial.print(time_stamp);
      Serial.println(led_d_state == HIGH ? "Turn off D" : "Turn on D");
    }
    
  }
//  digitalWrite(LEDA, HIGH);
//  delay(CURRENT_SPEED);
//  digitalWrite(LEDA, LOW);
//  delay(CURRENT_SPEED);
}
