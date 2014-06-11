#include "TinyJS.h"
#include "TinyJS_Functions.h"
#include <assert>
#include <stdio.h>

const char *code = "function myfunc(x, y) { return x + y; } var a = myfunc(1, 2); print(a);";

void js_print(CScriptVar *v, void *userdata) {
	printf("> %s\n", v->getParameter("text")->getString().c_str());
}

void js_dump(CScriptVar *v, void *userdata) {
	CTinyJS *js = (CTinyJS*)userdata;
	js->root->trace("> ");
}

int main(int argc, char **argv) {

	CTinyJS *js = new CTinyJS();

	registerFunction(js);

	js->addNative("function print(text)", &js_print, 0);
	js->addNative("function dump()", &js_dump, js);

	try {
		js->evaluate("var lets_quit = 0; function quit() { lets_quit = 1; }");
		js->evaluate("print(\"Interactive mode... type quit(); to exit, or to print(...) to print something, or dump() to dump the symbol tables.\");");
	} catch (CScriptException *e) {
		print("ERROR: %s\n", e->text.c_str());
	}

	while (js->evaluate("lets_quit") == "0") {
		char buffer[2048];
		gets(buffer);
		if (buffer[0] == '\0') break;

		try {
			js->evaluate(buffer);
		} catch (CScriptException *e) {
			printf("ERROR: %s\n", e->text.c_str());
		}
	}

	delete js;

#ifdef _WIN32
	#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
	#endif
#endif

	return 0;
}