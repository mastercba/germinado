#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"



void main_task(void *pvParameter)
{
    while(1) {
        printf( "%s\n", "Task1" ); //CONFIG_HELLO_MESSAGE );

        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void main_task2(void *pvParameter)
{
    while(1) {
        printf( "%s\n", "Task2" );

        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void main_task3(void *pvParameter)
{
    while(1) {
        printf( "%s\n", "Task3" );

        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

void app_main()
{
    nvs_flash_init();
    //system_init();

    xTaskCreatePinnedToCore(&main_task, "main_task", 2048, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(&main_task2, "main_task2", 2048, NULL, 5, NULL, 0);
    xTaskCreatePinnedToCore(&main_task3, "main_task3", 2048, NULL, 9, NULL, 0);
}
