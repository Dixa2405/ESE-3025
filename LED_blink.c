#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

#define LED_ON  0
#define LED_OFF 1

int RED =0;
int GREEN =1;
int BLUE =2;

static void prvSetupHardware(void)

{
SystemCoreClockUpdate();
Board_Init();

/* Initial LEDs state is off */
Board_LED_Set(0, LED_OFF);
Board_LED_Set(1, LED_OFF);
Board_LED_Set(2, LED_OFF);
}

/*thread for red LED*/
static void task1(void *pvParameters)
{

        int LED_Number= *(int*)pvParameters;
        while (1) {

Board_LED_Set(LED_Number,LED_ON);       // task on for 1 Second
vTaskDelay(configTICK_RATE_HZ);

Board_LED_Set(LED_Number,LED_OFF);      // task1 off for 3.5 Second
vTaskDelay(3*configTICK_RATE_HZ+ configTICK_RATE_HZ/2);

}
}

/* thread for green LED*/
static void task2(void *pvParameters) 
{
	int LED_Number= *(int*)pvParameters;
	vTaskDelay(configTICK_RATE_HZ+configTICK_RATE_HZ/2);

        while (1) {

Board_LED_Set(LED_Number,LED_ON);       // geen led will on for 1 Second
vTaskDelay(configTICK_RATE_HZ);

Board_LED_Set(LED_Number,LED_OFF);      //  off for 3.5 Second
vTaskDelay(3*configTICK_RATE_HZ+ configTICK_RATE_HZ/2);

}
}

/*  thread for blue LED */
static void task3(void *pvParameters) {
	int LED_Number= *(int*)pvParameters;
	vTaskDelay(3*configTICK_RATE_HZ);

        while (1) {

Board_LED_Set(LED_Number,LED_ON);       //blue LED will on for 1 Second
vTaskDelay(configTICK_RATE_HZ);

Board_LED_Set(LED_Number,LED_OFF);      //off for 3.5 Second
vTaskDelay(3*configTICK_RATE_HZ+ configTICK_RATE_HZ/2);

}
}

/*public functions

int main(void)
{
prvSetupHardware();



/* RED LED thread */
xTaskCreate(task1, (signed char *) "RED",
configMINIMAL_STACK_SIZE, (void*)&RED, (tskIDLE_PRIORITY + 3UL),
(xTaskHandle *) NULL);

/* GREEN LED thread */
xTaskCreate(task2, (signed char *) "GREEN",
configMINIMAL_STACK_SIZE, (void*)&GREEN, (tskIDLE_PRIORITY + 2UL),
(xTaskHandle *) NULL);

/* BLUE LED thread */
xTaskCreate(task3, (signed char *) "BLUE",
configMINIMAL_STACK_SIZE, (void*)&BLUE, (tskIDLE_PRIORITY + 1UL),
(xTaskHandle *) NULL);

vTaskStartScheduler();

return 1;
}
