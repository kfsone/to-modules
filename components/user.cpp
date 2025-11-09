module components;  // NOTE: module *not* partition
// automatic visibility of other partitions,
// import :db;  // if we want to be explicit

User NewUser(DB& db, std::string name)  // note: all 3 types are visible
{
	db.log(LOG_INFO, "create user " + name);
	return User{ .name = name };
}
