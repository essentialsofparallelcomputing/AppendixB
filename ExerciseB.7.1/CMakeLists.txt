cmake_minimum_required (VERSION 3.0)
project (vecadd)

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

# Adds build target of vecadd with source code files
add_executable(vecadd vecadd.c timer.c timer.h)
set_target_properties(vecadd PROPERTIES COMPILE_FLAGS ${VECTOR_C_FLAGS})
set_target_properties(vecadd PROPERTIES COMPILE_FLAGS ${OpenMP_C_FLAGS})
set_target_properties(vecadd PROPERTIES LINK_FLAGS "${OpenMP_C_FLAGS}")

# Cleanup
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles
                  Makefile cmake_install.cmake vecadd.dSYM ipo_out.optrpt)
