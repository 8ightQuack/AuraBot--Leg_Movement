#include "iot_servo.h"

#define SERVO_FL    2   // pin numbers for legs
#define SERVO_FR    4
#define SERVO_RL    18
#define SERVO_RR    19

void servo_init(void)
{

    // Configure the servo
    servo_config_t servo_cfg = {
        .max_angle = 180,
        .min_width_us = 500,
        .max_width_us = 2500,
        .freq = 50,
        .timer_number = LEDC_TIMER_0,
        .channels = {
            .servo_pin = {
                SERVO_FL,
                SERVO_FR,
                SERVO_RL,
                SERVO_RR
            },
            .ch = {
                LEDC_CHANNEL_0, // front left
                LEDC_CHANNEL_1, // front right
                LEDC_CHANNEL_2, // rear  left
                LEDC_CHANNEL_3  // rear  right
            },
        },
        .channel_number = 4,
    };

    // Initialize the servo
    iot_servo_init(LEDC_LOW_SPEED_MODE, &servo_cfg);
}

void FL_angle(int angle)
{
    iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 0, angle);
}

void FR_angle(int angle)
{
    iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 1, 180 - angle);
}

void RL_angle(int angle)
{
    iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 2, angle);
}

void RR_angle(int angle)
{
    iot_servo_write_angle(LEDC_LOW_SPEED_MODE, 3, 180 - angle);
}