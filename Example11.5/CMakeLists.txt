cmake_minimum_required(VERSION 3.10)
project (mass_sum)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set (CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O3")

if (NOT CMAKE_OPENMPACCEL_VERBOSE)
    set(CMAKE_OPENMPACCEL_VERBOSE true)
endif (NOT CMAKE_OPENMPACCEL_VERBOSE)

if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing")
elseif (CMAKE_C_COMPILER_ID MATCHES "Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing")
elseif (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -qalias=ansi")
elseif (CMAKE_C_COMPILER_ID MATCHES "Cray")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -h restrict=a")
endif (CMAKE_C_COMPILER_ID MATCHES "GNU")

find_package(OpenMPAccel)

if (CMAKE_C_COMPILER_ID MATCHES "XL")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -qreport")
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(OpenMPAccel_C_FLAGS "${OpenMPAccel_C_FLAGS} -fopt-info-omp")
endif (CMAKE_C_COMPILER_ID MATCHES "XL")

if (CMAKE_OPENMPACCEL_VERBOSE)
    set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} ${OpenACC_C_VERBOSE}")
endif (CMAKE_OPENMPACCEL_VERBOSE)

find_package(CUDA)

# Adds build target of mass_sum with source code files
add_executable(mass_sum mass_sum.c main.c)
set_source_files_properties(mass_sum.c PROPERTIES COMPILE_FLAGS "${OpenMPAccel_C_FLAGS}")
set_target_properties(mass_sum PROPERTIES LINK_FLAGS "${OpenMPAccel_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake mass_sum.dSYM ipo_out.optrpt mass_sum.o main.o)
