#include <esp_log.h>

#include "init.h"

#define TAG "init"

extern initfunc_t __start_initcalls;
extern initfunc_t __stop_initcalls;

static void run_init(initfunc_t *first, initfunc_t *last) {
    ESP_LOGI(TAG, "Init area: %zu funcs (start: %p, stop: %p)", last - first, first, last);
    while (first < last) {
        ESP_LOGI(TAG, "Calling init %p", *first);
        (*first++)();
    }
}

void init() {
    ESP_LOGI(TAG, "Running init");
    run_init(&__start_initcalls, &__stop_initcalls);
    ESP_LOGI(TAG, "Init done");
}
