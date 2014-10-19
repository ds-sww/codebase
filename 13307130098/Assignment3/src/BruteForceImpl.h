/**
 * @author sunqinzheng
 * @date   2014.10.13
 *
 */

#include "Matcher.h"
#include <string>
using namespace std;

class BruteForceImpl : public Matcher {
    
    private :
        string pattern;


    public :
        BruteForceImpl(const string& p);

        int find(string text);
        
        ~BruteForceImpl();
};



