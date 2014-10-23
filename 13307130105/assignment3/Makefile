
all : compile 

compile :
	g++ -O2 -march=native -o tester MatcherTest.cpp BoyerMooreImpl.cpp KarpRabinImpl.cpp KMPImpl.cpp

genData :
	./tester genData; python gen.py >> genData.txt

allImpl : BF KR KMP BM

BF :
	./tester BF

KR :
	./tester KR

KMP :
	./tester KMP

BM :
	./tester BM

clean :
	rm -rf tester genData.txt
