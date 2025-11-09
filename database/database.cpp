module database;		// no 'export', this is the implementation

import logging;			// since 'database' doesn't 'export' it.

// import <string>;		// ? unsure if not-needing this is msvc bug

DB NewDatabase()
{
	DB db{.log = NewLogger("db")};
	db.log(LOG_INFO, "opened db");
	return db;
}
