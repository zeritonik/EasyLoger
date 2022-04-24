#include "EasyLoger.h"


int main()
{
	{
		EasyLoger el;

		el.info("info");
		el.info(200);
		el.special_info("special_info");
		el.special_info(200);
		el.warn("warn");
		el.warn(200);
		el.error("error");
		el.error(200);
	}

	{
		NamedEasyLoger el("NamedTest");

		el.info("info");
		el.info(200);
		el.special_info("special_info");
		el.special_info(200);
		el.warn("warn");
		el.warn(200);
		el.error("error");
		el.error(200);
	}

	{
		TimedEasyLoger el;

		el.info("info");
		el.info(200);
		el.special_info("special_info");
		el.special_info(200);
		el.warn("warn");
		el.warn(200);
		el.error("error");
		el.error(200);
	}

	{
		NamedTimedEasyLoger el("NamedTimedTest");

		el.info("info");
		el.info(200);
		el.special_info("special_info");
		el.special_info(200);
		el.warn("warn");
		el.warn(200);
		el.error("error");
		el.error(200);
	}

	return 0;
}