cmake_minimum_required (VERSION 3.0)
project (max_reduction)

set (CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Vector)

if (CMAKE_VECTOR_VERBOSE)
   set(VECTOR_C_FLAGS "${VECTOR_C_FLAGS} ${VECTOR_C_VERBOSE}")
endif (CMAKE_VECTOR_VERBOSE)
if (CMAKE_VECTOR_NOVEC)
   set(VECTOR_C_FLAGS "${VECTOR_NOVEC_C_FLAGS}")
endif (CMAKE_VECTOR_NOVEC)

find_package(OpenMP)

# Adds build target of max_reduction with source code files
add_executable(max_reduction main.c max_reduction.c timer.c timer.h)
set_target_properties(max_reduction PROPERTIES COMPILE_FLAGS ${VECTOR_C_FLAGS})
set_target_properties(max_reduction PROPERTIES COMPILE_FLAGS ${OpenMP_C_FLAGS})
set_target_properties(max_reduction PROPERTIES LINK_FLAGS "${OpenMP_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake max_reduction.dSYM ipo_out.optrpt)
