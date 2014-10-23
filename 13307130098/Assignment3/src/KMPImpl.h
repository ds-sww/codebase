/**
 * @author sunqinzheng
 * @date 2014.10.15
 */


#include <string>
#include <vector>
#include "Matcher.h"
using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        vector<int> prev;

    public :
        KMPImpl(string p);

        int find(string text);

        ~KMPImpl();
};
