//-----------------------------------------------------------
// Marginally Clever RUMBA test suite
// If your board doesn't pass these tests we don't want you.
// 2017-04-27 dan@marginallyclever.com 
//-----------------------------------------------------------

//-----------------------------------------------------------
// CONSTANTS
//-----------------------------------------------------------

#define MOTOR_0_DIR_PIN    (16)
#define MOTOR_0_STEP_PIN   (17)
#define MOTOR_0_ENABLE_PIN (48)

#define MOTOR_1_DIR_PIN    (47)
#define MOTOR_1_STEP_PIN   (54)
#define MOTOR_1_ENABLE_PIN (55)

#define NUM_PINS           (8)
#define STEP_DELAY         (500)  //us
#define STEPS_PER_TURN     (400)

#define SERVO0_PIN         (5)

//-----------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------

#include <Servo.h>

//-----------------------------------------------------------
// GLOBALS
//-----------------------------------------------------------

int pins[NUM_PINS] = {
  MOTOR_0_DIR_PIN   ,
  MOTOR_0_STEP_PIN  ,
  MOTOR_0_ENABLE_PIN,
  MOTOR_1_DIR_PIN   ,
  MOTOR_1_STEP_PIN  ,
  MOTOR_1_ENABLE_PIN,
};


Servo s;

//-----------------------------------------------------------
// METHODS
//-----------------------------------------------------------

void setup() {
  Serial.begin(57600);
  Serial.println("\n\nSTART");
  // put your setup code here, to run once:
  for(int i=0;i<NUM_PINS;++i) {
    pinMode(pins[i],OUTPUT);
  }
  s.attach(SERVO0_PIN);
  Serial.println("\n\nREADY\n");
}


void loop() {
  Serial.println("HIGH");
  // put your main code here, to run repeatedly:
  digitalWrite(MOTOR_0_ENABLE_PIN,HIGH);
  digitalWrite(MOTOR_1_ENABLE_PIN,HIGH);
  fullTurnAndBack();
  Serial.println("LOW");
  digitalWrite(MOTOR_0_ENABLE_PIN,LOW);
  digitalWrite(MOTOR_1_ENABLE_PIN,LOW);
  fullTurnAndBack();

  s.write(180);
  delay(500);
  s.write(0);
  delay(500);
}

void fullTurnAndBack() {
  Serial.println("Forward");
  digitalWrite(MOTOR_0_DIR_PIN,HIGH);
  digitalWrite(MOTOR_1_DIR_PIN,HIGH);
  fullTurn();
  Serial.println("Backward");
  digitalWrite(MOTOR_0_DIR_PIN,LOW);
  digitalWrite(MOTOR_1_DIR_PIN,LOW);
  fullTurn();
}

void fullTurn() {
  int i;
  for(i=0;i<STEPS_PER_TURN;++i) {
    digitalWrite(MOTOR_0_STEP_PIN,HIGH);
    digitalWrite(MOTOR_1_STEP_PIN,HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(MOTOR_0_STEP_PIN,LOW);
    digitalWrite(MOTOR_1_STEP_PIN,LOW);
    delayMicroseconds(STEP_DELAY);
  }
}
