// export module I.Logz.ForU;  // NOTE: controls the name
export module logging;

#include <iostream>  // vs: produces warning, may fail on others
#include <string>    // vs: produces warning, may fail on others

// FIXME
#define LOG_INFO "info"
// export constexpr const char* LOG_INFO = "info";

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
