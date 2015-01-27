#include "XboxController.h"

XboxController::XboxController(uint32_t port) : Joystick(port){
}

float XboxController::GetLeftJoyX(){
	return GetRawAxis(1);
}

float XboxController::GetLeftJoyY(){
	return GetRawAxis(2);
}

float XboxController::GetRightJoyX(){
	return GetRawAxis(4);
}

float XboxController::GetRightJoyY(){
	return GetRawAxis(5);
}

bool XboxController::GetAButton(){
	return GetRawButton(1);
}

bool XboxController::GetBButton(){
	return GetRawButton(2);
}

bool XboxController::GetXButton(){
	return GetRawButton(3);
}

bool XboxController::GetYButton(){
	return GetRawButton(4);
}

bool XboxController::GetLBButton(){
	return GetRawButton(5);
}

bool XboxController::GetRBButton(){
	return GetRawButton(6);
}

bool XboxController::GetBackButton(){
	return GetRawButton(7);
}

bool XboxController::GetStartButton(){
	return GetRawButton(8);
}

bool XboxController::GetLeftJoyButton(){
	return GetRawButton(9);
}

bool XboxController::GetRightJoyButton(){
	return GetRawButton(10);
}

float XboxController::GetX(JoystickHand hand){
	return -Joystick::GetX(hand);
}

float XboxController::GetY(JoystickHand hand){
	return -Joystick::GetZ();
}
