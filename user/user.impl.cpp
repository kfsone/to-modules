module;
#include <string>

module user;
import database;
import logging;


User NewUser(DB& db, std::string name)
{
	db.log(LOG_INFO, "create user " + name);
	return User{ .name = name };
}
