/**
 * @author whimsycwd
 * @date   2014.10.2
 * bad character shift 和 good suffix shift 都是偏移的必要条件
 */

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

        BoyerMooreImpl(const string &pattern) {

        }

        virtual int find(const string &text) const {

            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};

