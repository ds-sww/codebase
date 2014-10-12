//  Created by forward on 10/12/14.
 

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Matcher.h"

using namespace std;


class BoyerMooreImpl : public Matcher {
    
    private :
        string pattern;

    public :

        explicit BoyerMooreImpl(const string &pattern) {
            this->pattern = pattern;
        }

        virtual int find(const string &text) {

            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};

