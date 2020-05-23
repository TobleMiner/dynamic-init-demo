#include <esp_log.h>

#include "init.h"

static void component_init() {
    ESP_LOGI("component 3", "Component 3 dynamic init");
}

INIT(component_init)
