export module components:user;

import :database;

export struct User
{
	std::string name;	// note: we can see std::string from :database.
};

export User NewUser(DB& db, std::string name);
