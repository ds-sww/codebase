/**
 * @author whimsycwd
 * @date   2014.10.1
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher {

    private :
        string pattern;


    public :
        explicit BruteForceImpl(const string& pattern) {
            this -> pattern = pattern;
        }

        virtual int find(string text) {
            if (text.size() < pattern.size())
                return NOT_FOUND;
            int ip, it;
            for (it = 0; it <= (text.size() - pattern.size()); it++){
                for (ip = 0; ip < pattern.size() && pattern[ip] == text[it+ip]; ip++) ;
                if (ip == pattern.size()) return it;
            }
            return NOT_FOUND;
        }

        virtual ~BruteForceImpl() {

        }
};



