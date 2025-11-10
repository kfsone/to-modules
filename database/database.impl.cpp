#include "database.h"

DB NewDatabase()
{
	DB db{ .log = NewLogger("db") };
	db.log(LOG_INFO, "opened db");
	return db;
}
