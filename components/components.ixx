export module components;

// If we determined everything in this module will need to
// see some recurring list of imports, importing it here
// in the top-level fragment would make it visible across
// the module.
//
// *BUT only to implementation units*.
//
// interface units are more compartmentalized, in particular
// they cannot see into the global fragment because they form
// a directed acyclical graph.
//
// import <string>;  // would only be visible to implementations
//
// if we wanted to avoid having to import <string> et al, we
// could create a "common" partition to contain and then
// import it without exporting.
//
// import :common;

export import :database;
export import :logging;
export import :user;
