
all : compile 

compile :
	g++ -O2 MatcherTest.cpp BruteForceImpl.cpp KarpRabinImpl.cpp KMPImpl.cpp BoyerMooreImpl.cpp -o Main

genData :
	./Main genData

allImpl : BF KR KMP BM

BF :
	./Main BF

KR :
	./Main KR

KMP :
	./Main KMP

BM :
	./Main BM

DBG :
	g++ -g MatcherTest.cpp BruteForceImpl.cpp KarpRabinImpl.cpp KMPImpl.cpp BoyerMooreImpl.cpp -o Main

Automata : 
	./Main Automata

clean :
	rm -rf Main genData.txt
