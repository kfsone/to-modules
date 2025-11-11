export module database;

#include <string>

import logging;

export struct DB
{
	Logger log;
};

export extern DB NewDatabase();
