import database;
import logging;
import user;

int main()
{
	Logger log  = NewLogger("main");
	DB     db   = NewDatabase();
	User   user = NewUser(db, "fred");

	log(LOG_INFO, "user is " + user.name);
}
