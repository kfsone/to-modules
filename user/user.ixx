module;
#include <string>

export module user;

import database;

export struct User
{
	std::string name;
};

export extern User NewUser(DB& db, std::string name);
