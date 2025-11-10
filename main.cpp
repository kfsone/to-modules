#include "database.h"
#include "user.h"

import logging;


int main()
{
	Logger log  = NewLogger("main");
	DB     db   = NewDatabase();
	User   user = NewUser(db, "fred");

	log(LOG_INFO, "user is " + user.name);
}
