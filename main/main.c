#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>

#include "init.h"

void app_main()
{
    ESP_LOGI("main", "Dynamic init example");

    init();

    while(true) {
        vTaskDelay(10);
    }
}
