#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "servo.h"

void delay_ms(int ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}