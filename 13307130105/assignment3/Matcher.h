
/**
 * @author whimsycwd
 * @date   2014.10.1
 */

#ifndef MATCHER_H
#define MATCHER_H 1

#include<string>

/**
 * The main purpose of this form is simplify test.
 *
 * Your implementation should extends this object. 
 * 1. XImpl should have an constructor XImpl(string text)
 * 2. Implement your `find(string pattern)`
 *
 * for example :
 * text = "ababcab"
 * pattern = "abc"
 * XImpl xImpl = new XImpl(pattern);
 * xImpl.find(text) should return 2 (start from 0, return the first matched substring index)
 *
 * more usage details in MatcherTest.
 *
 */
class Matcher {
    
    public :
        const static int NOT_FOUND = -1;
        virtual int find(std::string pattern) = 0;
        virtual ~Matcher() {
        }
};

#endif

