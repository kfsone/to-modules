module;
#include <string>

export module components:database;
import :logging;


export struct DB
{
	Logger log;
};

export extern DB NewDatabase();
