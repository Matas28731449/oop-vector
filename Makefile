main: clean
	g++ -std=c++17 -O3 -w -o main main.cpp functions.cpp
functions:
	g++ -std=c++17 -O3 -w -o functions.cpp
clean:
	rm -f *.o main