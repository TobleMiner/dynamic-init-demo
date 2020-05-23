#include <esp_log.h>

#include "init.h"

static void component_init(const char *str) {
    ESP_LOGI(__FILE__, "Component with args: %s", str);
}

INIT(component_init, "Hello World!")
