export module logging;

// FIXME (Stage 5)
#include <iostream>
#include <string>

export constexpr const char* LOG_INFO = "info";

export struct Logger
{
	std::string name;
    void operator() (const char* level, std::string msg)
	{
		std::cout << name << ":" << level << ": " << msg << std::endl;
	}
};

export inline Logger NewLogger(std::string name)
{
	return Logger{ .name = name };
}
