/**
 * @author sunqinzheng
 * @date   2014.10.15
 */

#include <string>
#include <vector>
#include <algorithm>
#include "Matcher.h"
using namespace std;


class BoyerMooreImpl : public Matcher {
    
    private :
        string pattern;
        vector<int> bc;
        vector<int> gs;
        vector<int> suffix;

    public :

        BoyerMooreImpl(string p);

        int find(string text);

        ~BoyerMooreImpl();
};

