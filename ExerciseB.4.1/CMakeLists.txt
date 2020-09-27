cmake_minimum_required (VERSION 2.8)
project (triangularallocation)

set (CMAKE_C_STANDARD 99)

# Adds build target of triangularallocation with source code files
add_executable(triangularallocation triangularallocation.c malloc2Dtri.c malloc2Dtri.h)

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake triangularallocation.dSYM ipo_out.optrpt)
