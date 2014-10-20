
all : compile run clean




genData :
	g++ gen.cpp -o genData
	./genData

compile :
	g++ main.cpp -o Main 


run : 
	./Main < in.txt

clean :
	rm -rf Main

compile_naive : 
	g++ main.cpp -o Main_naive

