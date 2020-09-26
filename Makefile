All: Example4.1 Example4.2 Example7.1 Example7.2

.PHONY: Example4.1 Example4.2 Example7.1 Example7.2

Example4.1:
	cd Example4.1 && mkdir build && cd build && cmake .. && make && \
	./triangularallocation

Example4.2:
	cd Example4.2 && mkdir build && cd build && cmake .. && make && \
	./fortranallocation

Example7.1:
	cd Example7.1 && mkdir build && cd build && cmake .. && make && \
	./vecadd

Example7.2:
	cd Example7.2 && mkdir build && cd build && cmake .. && make && \
	./max_reduction

clean:
	rm -rf Example4.1/build
	rm -rf Example4.2/build
	rm -rf Example7.1/build
	rm -rf Example7.2/build
