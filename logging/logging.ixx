export module logging;

// import <overkill.h>;     // uncomment to see effect
import <iostream>;
import <string>;
// If our users will always want to access std::string, we could
// in theory export it so they don't have to.
// export import <string>;

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
