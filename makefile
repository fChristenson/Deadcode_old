build:
	clang++ -stdlib=libc++ -o dead_code main.cpp

run: build
	./dead_code

clean:
	rm dead_code