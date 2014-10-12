compile :
	g++ MatcherTest.cpp -o Main

genData :
	./Main genData

pre: compile genData

BF : pre
	./Main BF

KR : pre
	./Main KR

KMP : pre
	./Main KMP

BM : pre
	./Main BM

Automata : pre
	./Main Automata

all : pre
	./Main BF
	./Main KR
	./Main KMP
	./Main BM
	./Main Automata

clean :
	rm -rf Main genData.txt
