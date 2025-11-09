// A pointless pile of includes that will slow down any
// compiler.

#pragma message ("-> overkill")
#include <cassert>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#include <bit>
#include <bitset>
#include <chrono>
#include <compare>
#include <complex>
#include <concepts>
#include <condition_variable>
#include <coroutine>
#include <deque>
#include <exception>
#include <filesystem>
#include <format>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <ios>
#include <iostream>
#include <istream>
#include <latch>
#include <list>
#include <locale>
#include <map>
#include <memory_resource>
#include <memory>
#include <mutex>
#include <numbers>
#include <optional>
#include <ostream>
#include <ranges>
#include <regex>
#include <semaphore>
#include <set>
#include <span>
#include <sstream>
#include <streambuf>
#include <string_view>
#include <string>
#include <syncstream>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <variant>
#include <vector>

#if __has_include(<unistd.h>)
#  include <unistd.h>
#endif
#if __has_include(<jthread>)
#  include <jthread>
#endif
#if __has_include(<Windows.h>)
#  include <Windows.h>
#endif

#pragma message ("<- overkill")
