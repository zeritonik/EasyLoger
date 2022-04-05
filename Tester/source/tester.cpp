#include "EasyLoger.h"


int main()
{
	{
		EasyLoger el;

		el.info("info");
		el.special_info("special_info");
		el.warn("warn");
		el.error("error");
	}

	{
		NamedEasyLoger el("NamedTest");

		el.info("info");
		el.special_info("special_info");
		el.warn("warn");
		el.error("error");
	}

	{
		TimedEasyLoger el;

		el.info("info");
		el.special_info("special_info");
		el.warn("warn");
		el.error("error");
	}

	{
		NamedTimedEasyLoger el("NamedTimedTest");

		el.info("info");
		el.special_info("special_info");
		el.warn("warn");
		el.error("error");
	}

	return 0;
}