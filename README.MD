# Description
Header-only Source SDK for Counter-Strike: Source with Linux target platform. It is written for modern C++ so that it can be compiled under C++20.

It is mostly written in *snake_case* and uses *CamelCase* for types such as classes and structs. (sort of Python style, except global variables are snake_case). It was decided to remove the *C* prefix before classes. So we use *BaseEntity* istead of *CBaseEntity*.

Everything is declared within ``mss`` namespace (abbreviation). So we use ``mss::BaseEntity`` for example.

Basically everything was parsed from the leaked Source SDK 2018, since it almost completely matches the current build of CS:S. There have been very few fixes and improvements and it should be completely consistent with the current game.

This SDK can be useful for learning the engine or developing something complicated since, for example, *SourceMod* can quite limit you in your desires and can make it more difficult to implement something.

There is much more that could be added, but what we have now may be quite enough for base development.

# Features
* All variables and virtual functions of ``CBaseEntity`` up to ``CCSPlayer`` are declared.
* Fully declared ``CGameClient`` and ``CBaseServer``.
* ``bf_write`` and ``bf_read`` definitions.
* ``CUtlVector``, ``CUtlMap`` and simalar definitions.
* All important interfaces and game declarations were included.

In general, the definition of ``CBaseEntity`` and ``CCSPlayer`` is the most convenient thing that can be, because you no longer need to look for offsets at runtime and believe it is networked or datamap property as *SourceMod* does.

# Why Linux is recommended?
Linux can be very convenient for development, mainly because all the debugging symbols were left out so that we can easily find addresses by their symbol, which is not the case in Windows where they were omitted. Also, in some other in-depth aspects Linux can be more relevant too (e.g. dynamic linking). Theoretically, this SDK could work on Windows too. It really could work, but not enough time was spent on it to check. And since most servers run on Linux, we have almost nothing to lose. Also, nowadays we can use [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) to develop on Linux while remaining on Windows so in this way we can get great convenience in development.

# Compilation
You can compile any source code (e.g. VSP) after including it with ``g++`` and ``clang++``. You may use these options:
* ``-m32`` - 32-bit compilation
* ``-shared`` - build as shared object
* ``-static-libstdc++`` - use the static standard library instead of what the game provides
* ``-std=c++2a`` - use modern standard (c++20)
* ``-Wl,-z,notext`` - disable relocation warnings
* ``-fno-gnu-unique`` (g++ only) - disable inline uniqueness to make *dlclose* work
