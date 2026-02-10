#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "servo.h"
#include "action.h"


int state = 0;  // default to standing
int nextState = 0;

void app_main(void)
{
    servo_init();
        printf("Enter next state: ");
        scanf("%d", &nextState);
        if (nextState != state) {
            state = nextState;
            printf("Changing to state %d\n", state);
        }
}