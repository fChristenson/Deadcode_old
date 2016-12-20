build: main.cpp
	clang++ -std=c++11 -stdlib=libc++ -o dead_code main.cpp

clean:
	rm dead_code