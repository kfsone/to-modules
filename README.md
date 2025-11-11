C++ Modules: For C++ Programmers
================================

- CMake 3.28+ required, CMake 4.0+ recommended
- VS2022 and Ninja Generators
- Tested with MSVC (2022, and "Insiders 2026"), CLang (18+, 20 was most robust)

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

- Stage 1 Introduces code
- Stage 2 Organizes code in a traditional librarization
- Stage 3 Migrates logging to a module (individual steps as Stage3.x)
- Stage 4 Migrates database and user to modules (see Stage4.x for steps)
- Stage 5 [Advanced] Demonstrates module partitions to combine the modules


## File Extensions

As of writing, extensions for module-related files are still somewhat
in the air, but between my compilers, IDEs and CMake I landed on:

.ixx:
  module interface unit (header-equivalent),
.impl.cpp: 
  module implementation (source-equivalent)

