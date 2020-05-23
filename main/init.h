#pragma once

void init();

typedef void (*initfunc_t)();

#define INIT(func, ...) \
    static void __init_##func() { \
        func(__VA_ARGS__); \
    } \
    static initfunc_t _init_##func __attribute__((section(".initcalls"), used)) = __init_##func;
