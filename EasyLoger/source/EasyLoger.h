#pragma once

#include <Windows.h>
#include <string>


class EasyLoger
{
private:
	static const char * out_format;

	const HANDLE output_handle;
	const WORD default_attribute;

	static WORD get_default_attribute();
	virtual void ColorOutput(const std::string& text, const WORD attribute) const;
public:
	EasyLoger();

	void info(const std::string& text) const;
	void special_info(const std::string& text) const;
	void warn(const std::string& text) const;
	void error(const std::string& text) const;
};