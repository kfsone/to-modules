#pragma once
#ifndef TUTORIAL_INCLUDED_USER_H
#define TUTORIAL_INCLUDED_USER_H

#include <database/database.h>

// FIXME (stage05)
#include <string>

struct User
{
	std::string name;
};

User NewUser(DB& db, std::string name);

#endif  // TUTORIAL_INCLUDED_USER_H
