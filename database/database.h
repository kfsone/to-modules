#pragma once
#ifndef TUTORIAL_INCLUDED_DATABASE_H
#define TUTORIAL_INCLUDED_DATABASE_H

#include <logging/logging.h>

struct DB
{
	Logger log;
};

extern DB NewDatabase();

#endif  // TUTORIAL_INCLUDED_DATABASE_H
