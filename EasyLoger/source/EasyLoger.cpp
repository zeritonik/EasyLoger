#include "EasyLoger.h"

#include <cstdio>
#include <ctime> // For TimedEasyLoger


// EasyLoger

WORD EasyLoger::get_default_attribute()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.wAttributes;
}

EasyLoger::EasyLoger():
	output_handle(GetStdHandle(STD_OUTPUT_HANDLE)),
	default_attribute(EasyLoger::get_default_attribute())
{

}

void EasyLoger::ColorOutput(const std::string& text, WORD attribute) const
{
	SetConsoleTextAttribute(output_handle, attribute);
	printf("%s\n", text.c_str());
	SetConsoleTextAttribute(output_handle, default_attribute);
}


void EasyLoger::info(const std::string& text) const
{
	ColorOutput(text, default_attribute);
}

void EasyLoger::special_info(const std::string& text) const
{
	ColorOutput(text, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void EasyLoger::warn(const std::string& text) const
{
	ColorOutput(text, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void EasyLoger::error(const std::string& text) const
{
	ColorOutput(text, FOREGROUND_RED | FOREGROUND_INTENSITY);
}


// NamedEasyLoger

NamedEasyLoger::NamedEasyLoger(const std::string& loger_name) :
	EasyLoger(), 
	name(loger_name)
{

}

void NamedEasyLoger::ColorOutput(const std::string& text, WORD attribute) const
{
	SetConsoleTextAttribute(output_handle, attribute);
	printf("%s - %s\n", name.c_str(), text.c_str());
	SetConsoleTextAttribute(output_handle, default_attribute);
}

// TimedEasyLoger

TimedEasyLoger::TimedEasyLoger() :
	EasyLoger()
{

}

void TimedEasyLoger::ColorOutput(const std::string& text, WORD attribute) const
{
	time_t now_time = time(NULL);
	tm timeinfo = { 0 };
	localtime_s(&timeinfo, &now_time);

	SetConsoleTextAttribute(output_handle, attribute);
	printf("[%02u:%02u:%02u] - %s\n", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, text.c_str());
	SetConsoleTextAttribute(output_handle, default_attribute);
}


// NamedTimedEasyLoger

NamedTimedEasyLoger::NamedTimedEasyLoger(const std::string& loger_name) :
	EasyLoger(),
	name(loger_name)
{

}


void NamedTimedEasyLoger::ColorOutput(const std::string& text, WORD attribute) const
{
	time_t now_time = time(NULL);
	tm timeinfo = { 0 };
	localtime_s(&timeinfo, &now_time);

	SetConsoleTextAttribute(output_handle, attribute);
	printf("%s[%02u:%02u:%02u] - %s\n", name.c_str(), timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec, text.c_str());
	SetConsoleTextAttribute(output_handle, default_attribute);
}