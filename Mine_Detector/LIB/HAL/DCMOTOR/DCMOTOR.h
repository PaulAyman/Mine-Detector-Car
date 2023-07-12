/*
 * DCMOTOR.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Paula Emad
 */

#ifndef LIB_HAL_DCMOTOR_DCMOTOR_H_
#define LIB_HAL_DCMOTOR_DCMOTOR_H_

#define motorLeftForward	PIN_7
#define motorLeftBackward	PIN_6
#define motorRightForward	PIN_5
#define motorRightBackward	PIN_4

void motor_Forward();
void motor_Backward();
void motor_Right();
void motor_LefT();
void motor_STOP();



#endif /* LIB_HAL_DCMOTOR_DCMOTOR_H_ */
