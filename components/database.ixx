export module components:database;

// While *Implementation Units* have automatic visibility across the
// module, interface units have to be explicit.
import :logging;

export
{

struct DB
{
	Logger log;
};

extern DB NewDatabase();

}  // export

