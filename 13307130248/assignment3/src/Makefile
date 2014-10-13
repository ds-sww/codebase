
all : compile 

compile :
	g++ MatcherTest.cpp -o Main

genData :
	./Main genData

allImpl : BF KR KMP BM

BF : compile
	./Main BF

KR :
	./Main KR

KMP :
	./Main KMP

BM :
	./Main BM

Automata : 
	./Main Automata

clean :
	rm -rf Main genData.txt
