module;
#include <string>

module components;


User NewUser(DB& db, std::string name)
{
	db.log(LOG_INFO, "create user " + name);
	return User{ .name = name };
}
