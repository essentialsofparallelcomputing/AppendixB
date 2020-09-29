all: SumReduction

CXX = hipcc

%.cc : %.cu
	hipify-perl $^ > $@

SumReduction: SumReduction.o timer.o
	${CXX} -o $@ $^ 

clean:
		rm -rf SumReduction *.o SumReduction.cc
