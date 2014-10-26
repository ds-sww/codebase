/**
 * @author Hermes777
 * @date   2014.10.1
 */

#ifndef MATCHER_H
#define MATCHER_H 1

#include<string>
class Matcher {

    public :
        const static int NOT_FOUND = -1;
        virtual int find(std::string pattern) = 0;
        virtual ~Matcher() {
        }
};

#endif
