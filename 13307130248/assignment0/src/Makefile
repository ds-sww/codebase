# an imitation of f0rward's makefile 
all: compile run clean

compile:
	g++ -std=c++11 HelloWorld.cpp -o HelloWorld

run:
	cat ../testcase/in.txt | ./HelloWorld > tmpout
	diff -q tmpout ../testcase/out.txt

clean:
	rm -f tmpout HelloWorld
