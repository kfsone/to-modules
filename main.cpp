#include <iostream>
#include <string>

// ---- Logging
#define LOG_INFO "info"

struct Logger
{
    std::string name;
    void operator() (const char* level, std::string msg)
	{
		std::cout << name << ":" << level << ": " << msg << std::endl;
	}
};

Logger NewLogger(std::string name)
{
	return Logger{ .name = name };
}


// ---- Data management
struct DB
{
	Logger log;
};

DB NewDatabase()
{
	DB db{ .log = NewLogger("db")};
	db.log(LOG_INFO, "opened db");
	return db;
}


// ---- User management
struct User
{
	std::string name;
};

User NewUser(DB& db, std::string name)
{
	db.log(LOG_INFO, "create user " + name);
	return User{ .name = name };
}


// ---- Application
int main()
{
	Logger log  = NewLogger("main");
	DB     db   = NewDatabase();
	User   user = NewUser(db, "fred");

	log(LOG_INFO, "user is " + user.name);
}
