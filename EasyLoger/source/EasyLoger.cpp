#include "EasyLoger.h"

#include <cstdio>

// EasyLoger

const char * EasyLoger::out_format = "%s\n";

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
	printf(out_format, text.c_str());
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