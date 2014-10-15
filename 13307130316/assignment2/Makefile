CXX=g++
FLAGS=-o

SORCES=$(shell ls *.cpp)
EXECUTABLE=exe

NUM=1 2

all: $(EXECUTABLE)

$(EXECUTABLE): $(SORCES)
	$(CXX) $^ $(FLAGS) $@

define runcase
@for num in $(NUM); do \
(cat ../testcase/$$num.in | ./$(EXECUTABLE) > ../src/$$num.tmp; diff $$num.tmp ../testcase/$$num.out ; rm -rf $$num.tmp) \
done;
endef


run: $(EXECUTABLE)
	$(call runcase) \

clean:
	rm -rf $(EXECUTABLE)
