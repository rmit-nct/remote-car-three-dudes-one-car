#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#define IN1_LF 4   
#define IN2_LF 5
#define IN3_RF 6
#define IN4_RF 7

#define IN1_LB 8
#define IN2_LB 9
#define IN3_RB 10
#define IN4_RB 11
 
 
void setup() {
  // put your setup code here, to run once:
  Dabble.begin(9600);    
  pinMode(IN1_LF, OUTPUT);
  pinMode(IN2_LF, OUTPUT);
  pinMode(IN3_RF, OUTPUT);
  pinMode(IN4_RF, OUTPUT);
  pinMode(IN1_LB, OUTPUT);
  pinMode(IN2_LB, OUTPUT);
  pinMode(IN3_RB, OUTPUT);
  pinMode(IN4_RB, OUTPUT);
  stop();
}

void go_forward(){
  digitalWrite(IN2_LF, LOW);
  analogWrite(IN1_LF, 255);

  digitalWrite(IN2_LB, LOW);
  analogWrite(IN1_LB, 255);

  digitalWrite(IN4_RF, LOW);
  analogWrite(IN3_RF, 255);

  digitalWrite(IN4_RB, LOW);
  analogWrite(IN3_RB, 255);
}

void go_backward(){
  digitalWrite(IN1_LF, LOW);
  analogWrite(IN2_LF, 255);

  // RIGHT FRONT
  digitalWrite(IN3_RF, LOW);
  analogWrite(IN4_RF, 255);

  // LEFT BACK
  digitalWrite(IN1_LB, LOW);
  analogWrite(IN2_LB, 255);

  // RIGHT BACK
  digitalWrite(IN3_RB, LOW);
  analogWrite(IN4_RB, 255);
}

void turn_right(){

  digitalWrite(IN3_RB, LOW);
  digitalWrite(IN4_RB, LOW);

   digitalWrite(IN3_RF, LOW);
  digitalWrite(IN4_RF, LOW);

  digitalWrite(IN2_LF, LOW);
  analogWrite(IN1_LF, 255);

  digitalWrite(IN2_LB, LOW);
  analogWrite(IN1_LB, 255);


}

void turn_left(){
  digitalWrite(IN1_LF, LOW);
  digitalWrite(IN2_LF, LOW);

  digitalWrite(IN1_LB, LOW);
  digitalWrite(IN2_LB, LOW);

  digitalWrite(IN4_RF, LOW);
  analogWrite(IN3_RF, 255);

  digitalWrite(IN4_RB, LOW);
  analogWrite(IN3_RB, 255);
}


void stop(){
  digitalWrite(IN1_LF, LOW);
  digitalWrite(IN2_LF, LOW);
  digitalWrite(IN3_RF, LOW);
  digitalWrite(IN4_RF, LOW);
  digitalWrite(IN1_LB, LOW);
  digitalWrite(IN2_LB, LOW);
  digitalWrite(IN3_RB, LOW);
  digitalWrite(IN4_RB, LOW);
}

void spinClockWire(){
  analogWrite(IN1_LF, 255);
  digitalWrite(IN2_LF, LOW);

  analogWrite(IN1_LB, 255);
  digitalWrite(IN2_LB, LOW);

  digitalWrite(IN3_RB, LOW);
  analogWrite(IN4_RB, 255);

  digitalWrite(IN3_RF, LOW);
  analogWrite(IN4_RF, 255);

}

void spinCounterClockWire(){
  analogWrite(IN2_LF, 255);
  digitalWrite(IN1_LF, LOW);

  analogWrite(IN2_LB, 255);
  digitalWrite(IN1_LB, LOW);

  digitalWrite(IN4_RB, LOW);
  analogWrite(IN3_RB, 255);

  digitalWrite(IN4_RF, LOW);
  analogWrite(IN3_RF, 255);
}


void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.

  
  if ( GamePad.isSquarePressed())
  {
    turn_left();
  }
  else if (GamePad.isCirclePressed())
  {
    turn_right();
  }
  else if (GamePad.isUpPressed())
  {
    go_forward();
  }
  else if (GamePad.isDownPressed())
  {
    go_backward();
  }
  else if (GamePad.isTrianglePressed()){
    spinClockWire();

  }
  else if (GamePad.isCrossPressed()){
    spinCounterClockWire();
    
  }
  else {
    stop();
  }
}
