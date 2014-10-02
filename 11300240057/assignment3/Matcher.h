
#ifndef MATCHER_H
#define MATCHER_H 1

#include<string>

class Matcher {
    
    public :
        const static int NOT_FOUND = -1;
        virtual int find(std::string text) = 0;
        virtual ~Matcher() {
        }
};

#endif

