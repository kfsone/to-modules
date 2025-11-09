C++ Modules: For C++ Programmers
================================

- CMake 3.31+ required, CMake 4.0+ recommended
- Tested with MSVC (2019, 2022, and "Insiders 2026")
- Pending (Clang, Gcc)


Practical, hands-on tutorial for folks who want to see how to make modules *happen*.

Not a "hello world" module guide or a standard dissertation. This project starts
from a reasonable simulation of a meaningful project.

I've organized this repos in incremental stages, represented by branches
named "Stage1", ... "Stage7". Use branch-diffs to see the evolution and/or
walk thru the process with me.

Some stages intentionally fail to surface common gotchas, you can either
try to manually fix them or simply observe and move past.

We start with a simple skeleton (main.cpp, here reduced for brevity):

```c++
// Reduced for readme
#include ...
#define ...

struct Logger { ... };
Logger NewLogger(std::string name) { ... }

struct DB { ... };
DB NewDatabase() { ... }

struct User { ... };
User NewUser(DB& db, std::string name) { ... }

int main() { ... }
```

The expectation is that you'll build each stage:
```sh
# -S .    read ./CMakeLists, build into ./build/
cmake -S . -B build 
# compile and build in ./build/
cmake --build build
```


First we'll expand that into a traditional C++ library organization,
and *then* we'll go to work turning that into modules.

- Stage 1 introduces the code in a single cpp that you can build/run,
- Stage 2 remaps that into logging (header-only), database, and user libs,
- Stage 3 naively converts logging to module implementation unit but does not compile,
- Stage 4 addresses one issue with Stage 3, but still does not compile,
- Stage 5 addresses the final issue with stage 3 and compiles,
- Stage 6 converts database and user to modules,
- Stage 7 creates a combined module demonstrating partition organization,


## Bonus: overkill.h

Look, most of us care about modules because of compile times. This file is a
piece of work that will take several seconds to process on a typical machine.

Include this from logging in stage 2 and stage 5 to see the difference that
modules makes.


## File Extensions

As of writing, extensions for module-related files are still somewhat
in the air, but between my compilers, IDEs and CMake I landed on:

.ixx:
  module interface unit (header-equivalent),
.impl.cpp: 
  module implementation (source-equivalent)


# Stage 0 - Begin

To get started switch branch to Stage 1; if you are using a command line:

```
git switch Stage1
```


# Stage 1 - Single File


A simple, single cpp file demonstrating the skeleton of a much larger system
that consists a logging suite, a database suite, and a user suite.

Take a moment to familiarize yourself with the code and the cross-dependencies.

```
cmake -S . -B build
cmake --build build
```


# Stage 2 - Tradition

We split the code into component libraries. Each a folder with a CMakeLists.txt
and CMake target.

The CMake should be unsurprising but take a moment to look at the .h/.cpp files.

Note `logging` is a header-only while the others are header + source.

*Recommended* Build as-is, then uncomment the line `#include "overkill.h"`
logging/logging.h line.

The impact on overall compile time should be very visible.


# Stage 3 - Transition

Naive stab at converting `logging.h` to a module.

logging.h:
- Rename to `logging.ixx` as this is going to be a "module interface unit",
(less scary if you think: `.h` usually denotes a `C or C++ header unit`)
- Add `module` and `export` statements,

CMakeLists:
- Unlike headers, module interface units are compiled once, directly, which
  means this is now a concrete target for CMake,
- Use CMake's `FILE_SET ... TYPE CXX_MODULES` to tell it this is a module
  *interface* unit
- Modify top-level CMakeLists to tell CMake that it will need to think
  about dependencies between modules.


## Note

- *Module name is determined by the `export module ...` statement.*
- Not automatically namespaced,
- Not based on filesystem or library/target,


## ERRORS

This first effort fails to compile for several reasons, but the first is
important.


# Stage 4 - Replace Macros

Collectively, what are `#if`, `#include`, `#pragma`?

"Compiler directive"? Effectively yes, but definitively no.

They are C's "pre-processor directive"s; a separate language that was even
originally handled by a completely separate parser.

For all intents and purposes an include directive pre-processes another file
and substitutes the text.

They are part of the C++ standard *but they are not part of the C++ language*.

For this an several other reasons, _modules do not expose macros_.

Here we replace `LOG_INFO` with a simple static constexpr.

*Note* I recommend using constexpr `string_view`s with the `sv` literal, but
opted to minimize the delta here.


## ERRORS: Crossed Streams

At the top of the build you should see warnings or errors about the use of
`#include` in a module context.

Might seem obnoxious in our simple use case but:
- module interface units are *compiled*, once;
- modules do not expose macros,
- #include is a pre-processor directive,

Not least of the issues then is include guards.

Modules provides a bridge by letting you combine include-like syntax with
the import statement:

```
// #include <cstdio>
import <cstdio>;
// #include "overkill.h"
import <overkill.h>;
```

There are `// FIXME` comments in `logging.h`.


# Stage 5 - Working Module

This branch builds with modding provided by a module.

Review the changes between this and Stage 1 (`git diff Stage1`).

_Recommended_ Edit logging/logging.h and have it include `overkill.h`,
and note how - despite logging being imported several times, we only
have to pay the cost of `overkill.h` once.


# Stage 6 - Conversion

Database and User both have source implementations, so here we demonstrate
how you **could** continue that strategy with modules.

For a "module implementation unit" file the first non-comment statement must
be a `module` directive.

*NOTE* I converted logging.h first to underline that you do not *have* to
use source + header files; interface units are themselves compiled.

Which brings us to: Stage 7


# Stage 7 - Different

In Stage 6 we persisted the traditional header/source separation of concerns,
and modules don't preclude you continuing to do so.

Here were going to demonstrate how modules tries to allow you to manage the
axes by which you manage concerns.

This doubles as a demonstration of how you can librarize multiple components.

*TAKEAWAYS*

If you take nothing else away about partitions it should be this: the
'module' directive always names the *module* and *never the partition*.

```
// module components:database;  // <-- wrong
module components;              // <-- correct
```

## Partitioning

Boilerplate: If you've done C++ for any period of time without modules you've
likely been conditioned to group things together certain ways to try and
minimize boiler plate.

Modules provide an additional dimension of scoping with shared visibility
between module partitions that you don't get when you're writing a library
with multiple separate source files.

So at the same time as I'm suggesting you should just put everything into
the interface unit file (in some cases) modules are also here to help you
employ *better* strategies for splitting up complex code.



