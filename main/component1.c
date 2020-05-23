#include <esp_log.h>

#include "init.h"

static void component_init() {
    ESP_LOGI("component 1", "Component 1 dynamic init");
}

INIT(component_init)
