// import I.Logz.ForU;
import logging;

#include <database/database.h>
#include <user/user.h>


int main()
{
	Logger log  = NewLogger("main");
	DB     db   = NewDatabase();
	User   user = NewUser(db, "fred");

	log(LOG_INFO, "user is " + user.name);
}
