#include "Test.h"
#include <locale>
#include <crtdbg.h>

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	setlocale(0,"swedish");
	testing();

	return 0;
}