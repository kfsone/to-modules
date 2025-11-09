export module user;

import database;

import <string>;

export struct User
{
	std::string name;
};

export User NewUser(DB& db, std::string name);
