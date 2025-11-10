#pragma once
#ifndef INCLUDED_DATABASE_H
#define INCLUDED_DATABASE_H

#include "logging.h"

struct DB
{
	Logger log;
};

extern DB NewDatabase();

#endif  // INCLUDED_DATABASE_H
