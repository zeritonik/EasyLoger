#pragma once

#include <Windows.h>
#include <string>


class EasyLoger
{
private:
	static WORD get_default_attribute();
	virtual void ColorOutput(const std::string& text, const WORD attribute) const;

protected:
	const HANDLE output_handle;
	const WORD default_attribute;

public:
	EasyLoger();

	void info(const std::string& text) const;
	void special_info(const std::string& text) const;
	void warn(const std::string& text) const;
	void error(const std::string& text) const;
};


class NamedEasyLoger : public EasyLoger
{
private:
	const std::string name;

	void ColorOutput(const std::string& text, const WORD attribute) const;
public:
	NamedEasyLoger(const std::string& loger_name);
};


class TimedEasyLoger : public EasyLoger
{
private:
	void ColorOutput(const std::string& text, const WORD attribute) const;
public:
	TimedEasyLoger();
};


class NamedTimedEasyLoger : public EasyLoger
{
private:
	const std::string name;

	void ColorOutput(const std::string& text, const WORD attribute) const;
public:
	NamedTimedEasyLoger(const std::string& loger_name);
};