
.PHONY: all build

all: build

build:
	g++ -std=c++11 -o cpp-logger ./main.cpp


