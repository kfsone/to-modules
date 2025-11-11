module;
#include <string>

export module database;

import logging;

export struct DB
{
	Logger log;
};

export extern DB NewDatabase();
