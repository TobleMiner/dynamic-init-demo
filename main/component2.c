#include <esp_log.h>

#include "init.h"

static void component_init() {
    ESP_LOGI("component 2", "Component 2 dynamic init");
}

INIT(component_init)
