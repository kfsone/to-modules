#pragma once
#ifndef INCLUDED_LOGGING_H
#define INCLUDED_LOGGING_H

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


// In order to avoid collisions between includes, must be static.
static inline Logger NewLogger(std::string name)
{
	return Logger{ .name = name };
}


#endif  // INCLUDED_LOGGING_H
