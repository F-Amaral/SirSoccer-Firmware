#include <Header.h>
#include <sirmotor.h>


Motor * motor = new Motor(MotorAPWM, MotorA1, MotorA2, MotorBPWM, MotorB1, MotorB2, STDBY);
unsigned long timestamp = 0;
int xbeeBuffer[4] = {0, 0, 0, 0};
void setup() {
  //Serial.begin(57600);
  Serial1.begin(57600);
  motor->motorInit();
}

Command old;

void loop() {
  moveRobot(receiveMessage());

}

Command receiveMessage() {
  Command cmd;
  if (Serial1.available() > 4) {
    if (Serial1.read() == 10) {
      int i = 0;
      while (Serial1.peek() != 11) {
        xbeeBuffer[i] = Serial1.read();
        i++;
      }
    }
  }
  switch (xbeeBuffer[0]) {
    case 0:
      cmd.directionA = 0;
      cmd.directionB = 0;
      break;
    case 1:
      cmd.directionA = 0;
      cmd.directionB = 1;
      break;
    case 16:
      cmd.directionA = 1;
      cmd.directionB = 0;
      break;
    case 17:
      cmd.directionA = 1;
      cmd.directionB = 1;
      break;
  }
  cmd.pwmA = xbeeBuffer[1];
  cmd.pwmB = xbeeBuffer[2];
 
  return cmd;
}

void moveRobot(Command cmd) {
  motor->updateMotor(cmd.directionA, cmd.pwmA, cmd.directionB, cmd.pwmB);
  motor->startMotor();
}

void updateOld(Command cmd) {
  old.directionA = cmd.directionA;
  old.directionB = cmd.directionB;
  old.pwmA = cmd.pwmA;
  old.pwmB = cmd.pwmB;
}
