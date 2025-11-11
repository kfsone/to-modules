module;
#include <string>

export module components:database;


export struct DB
{
	Logger log;
};

export extern DB NewDatabase();
