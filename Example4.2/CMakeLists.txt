cmake_minimum_required (VERSION 2.8)
project (fortranallocation)

set (CMAKE_C_STANDARD 99)

# Adds build target of fortranallocation with source code files
add_executable(fortranallocation fortranallocation.c malloc2Dfort.c malloc2Dfort.h)

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake fortranallocation.dSYM ipo_out.optrpt)
