
all : compile 

compile :
	g++ MatcherTest.cpp -o Main

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


clean :
	rm -rf Main genData.txt
