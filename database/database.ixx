export module database;

import logging;

// We could individually export:
// export struct DB { Logger log; };
// export DB NewDatabase();

// But we can also introduce an 'export' block, or an 'export namespace' block.
export
{

struct DB
{
	Logger log;
};

extern DB NewDatabase();

}  // export

