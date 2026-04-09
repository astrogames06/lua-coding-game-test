#ifndef UTILS_H
#define UTILS_H

#include <emscripten/emscripten.h>
#include <string>

EM_JS(void, js_alert, (const char* str), {
    alert(UTF8ToString(str));
});

#endif
