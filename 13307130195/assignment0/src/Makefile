# a simple makefile

all: compile run clean

compile:
	g++ -std=c++11 Add.cpp -o add

run:
	cat ../testcase/in.txt | ./add > tmpout
	diff --brief tmpout ../testcase/out.txt 

clean:
	rm -f tmpout add