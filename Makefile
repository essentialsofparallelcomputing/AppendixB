All: Example4.1 Example4.2 Example7.1 Example7.2 Example7.3 Example11.5 Example11.6

.PHONY: Example4.1 Example4.2 Example7.1 Example7.2 Example7.3 Example11.5 Example11.6

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

Example7.3:
	cd Example7.3 && mkdir build && cd build && cmake .. && make && \
	./max_reduction

Example11.5:
	cd Example11.5 && mkdir build && cd build && cmake .. && make && \
	./mass_sum

Example11.6:
	cd Example11.6 && mkdir build && cd build && cmake .. && make && \
	./MaxRadius

clean:
	rm -rf Example4.1/build
	rm -rf Example4.2/build
	rm -rf Example7.1/build
	rm -rf Example7.2/build
	rm -rf Example7.3/build
	rm -rf Example11.5/build
	rm -rf Example11.6/build
