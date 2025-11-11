module;
#include <string>

export module components:user;


export struct User
{
	std::string name;
};

export extern User NewUser(DB& db, std::string name);
