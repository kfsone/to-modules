#pragma once
#ifndef INCLUDED_DATABASE_H
#define INCLUDED_DATABASE_H

import logging;

struct DB
{
	Logger log;
};

extern DB NewDatabase();

#endif  // INCLUDED_DATABASE_H
