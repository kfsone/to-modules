#pragma once
#ifndef TUTORIAL_INCLUDED_LOGGING_H
#define TUTORIAL_INCLUDED_LOGGING_H

// #include <overkill.h>		// uncomment for slow compiles
#include <iostream>
#include <string>

#define LOG_INFO "info"

struct Logger
{
	std::string name;
    void operator() (const char* level, std::string msg)
	{
		std::cout << name << ":" << level << ": " << msg << std::endl;
	}
};

// This would cause multiple symbols if we didn't make it static,
// but we can also make it inline (but not constexpr).
static inline Logger NewLogger(std::string name)
{
	return Logger{ .name = name };
}

#endif  // TUTORIAL_INCLUDED_LOGGING_H
