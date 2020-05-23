#include <esp_log.h>

#include "init.h"

static void component_init() {
    ESP_LOGI(__FILE__, "Component 2 dynamic init");
}

INIT(component_init)
