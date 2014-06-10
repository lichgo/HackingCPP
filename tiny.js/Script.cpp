#include "TinyJS.h"
#include "TinyJS_Functions.h"
#include <assert>
#include <stdio.h>

const char *code = "function myfunc(x, y) { return x + y; } var a = myfunc(1, 2); print(a);";


int main(int argc, char **argv) {
	CTinyJS *js = new CTinyJS();

	registerFunction(js);

	js->addNative("function print(text)", &js_print, 0);
	js->addNative("function dump()", &js_dump, js);
}