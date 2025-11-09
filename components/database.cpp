module components;  // NOTE: Module, not partition.
// no imports required: automatic visibility of other partitions, 
// import :logging;  // if we wanted to be explicit.

DB NewDatabase()
{
	DB db{.log = NewLogger("db")};
	db.log(LOG_INFO, "opened db");
	return db;
}
