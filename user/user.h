#pragma once
#ifndef INCLUDED_USER_H
#define INCLUDED_USER_H

#include "database.h"

#include <string>

struct User
{
	std::string name;
};

extern User NewUser(DB& db, std::string name);

#endif  // INCLUDED_USER_H
