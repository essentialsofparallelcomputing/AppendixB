All: Improved Original

.PHONY: Improved Original

Improved:
	cd Improved && mkdir build && cd build && cmake .. && make && export OMP_NUM_THREADS=2 && mpirun -n 2 ./CartExchange

Original:
	cd Original && mkdir build && cd build && cmake .. && make && export OMP_NUM_THREADS=2 && mpirun -n 2 ./CartExchange

clean:
	rm -rf Improved/build
	rm -rf Original/build
