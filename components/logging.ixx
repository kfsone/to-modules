module;

#include <iostream>
#include <string>

export module components:logging;

export constexpr const char* LOG_INFO = "info";
// A better alternative would be to use std::string_view:
// using namespace std::string_view_literals;
// export constexpr std::string_view kLOG_INFO = "info"sv;

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
