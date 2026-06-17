/*
 * motor_control.h
 * ---------------
 * Module: Motor Control
 * Phase:  1 - Arduino Navigation Firmware
 *
 * PURPOSE:
 *   Provides a clean interface to drive two DC motors via the L298N
 *   motor driver. All pin knowledge is contained here so every other
 *   module just calls driveMotors() without knowing hardware details.
 *
 * INPUTS:
 *   leftSpeed, rightSpeed: integers from -255 to +255
 *     Positive = forward, Negative = reverse, 0 = stop
 *
 * OUTPUTS:
 *   PWM signals to L298N ENA/ENB
 *   Direction signals to L298N IN1-IN4
 *
 * WIRING (from Wiring Guide V7):
 *   Pin 5  -> ENA  (Left motor PWM speed)
 *   Pin 6  -> IN1  (Left motor direction A)
 *   Pin 7  -> IN2  (Left motor direction B)
 *   Pin 8  -> IN3  (Right motor direction A)
 *   Pin 9  -> IN4  (Right motor direction B)
 *   Pin 10 -> ENB  (Right motor PWM speed)
 */

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

// Left motor pins
#define PIN_ENA   5   // PWM speed control for left motor
#define PIN_IN1   6   // Left motor direction pin A
#define PIN_IN2   7   // Left motor direction pin B

// Right motor pins
#define PIN_ENB   10  // PWM speed control for right motor
#define PIN_IN3   8   // Right motor direction pin A
#define PIN_IN4   9   // Right motor direction pin B

// Speed limits
#define MOTOR_MAX_SPEED   255
#define MOTOR_MIN_SPEED   0

/*
 * motorControlInit()
 * Sets all motor pins as OUTPUT and ensures motors start stopped.
 * Call once in setup().
 */
void motorControlInit();

/*
 * driveMotors(leftSpeed, rightSpeed)
 * Drive both motors at the given speeds simultaneously.
 *   leftSpeed:  -255 to +255 (negative = reverse)
 *   rightSpeed: -255 to +255 (negative = reverse)
 * Values outside range are clamped automatically.
 */
void driveMotors(int leftSpeed, int rightSpeed);

/*
 * motorsStop()
 * Immediately stops both motors with active braking.
 * Preferred over driveMotors(0, 0) in safety situations.
 */
void motorsStop();

/* motorsForward(speed) - Both motors forward at equal speed. 0 to 255. */
void motorsForward(int speed);

/* motorsReverse(speed) - Both motors backward at equal speed. 0 to 255. */
void motorsReverse(int speed);

/* motorsTurnLeft(speed) - Pivot left: left motor back, right motor forward. */
void motorsTurnLeft(int speed);

/* motorsTurnRight(speed) - Pivot right: left motor forward, right motor back. */
void motorsTurnRight(int speed);

#endif // MOTOR_CONTROL_H