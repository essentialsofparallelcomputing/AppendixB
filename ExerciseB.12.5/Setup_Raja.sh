#!/bin/sh
export INSTALL_DIR=`pwd`/build/Raja
export Raja_DIR=${INSTALL_DIR}/share/raja/cmake

mkdir -p build/Raja_tmp && cd build/Raja_tmp
cmake ../../Raja_build -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR}
make -j 8 install && cd .. && rm -rf Raja_tmp

cmake .. && make && ./StreamTriad
