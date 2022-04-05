#include "EasyLoger.h"


int main()
{
	EasyLoger el;

	el.info("info");
	el.special_info("special_info");
	el.warn("warn");
	el.error("error");

	return 0;
}