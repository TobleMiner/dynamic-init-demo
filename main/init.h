#pragma once

void init();

typedef void (*initfunc_t)();

#define INIT(func) \
    static void __init_##func() { \
        func(); \
    } \
    static initfunc_t _init_##func __attribute__((section(".initcalls"), used)) = __init_##func;
