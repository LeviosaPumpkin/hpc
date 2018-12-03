binary: main.o cosx.so
	g++ -o binary main.o -L. -lcosx -Wl,-rpath,.

main.o: main.cpp
	g++ -c -O3 -march=native -mfpmath=sse -ftree-vectorize -std=c++11 -lm -fopenmp  main.cpp

cosx.so: Vector.o
	g++ -shared -o cosx.so Vector.o 

clean:
	rm -f *.o *.so binary
