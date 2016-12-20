build:
	clang++ -o dead_code main.cpp

run: clean build
	./dead_code

clean:
	rm dead_code