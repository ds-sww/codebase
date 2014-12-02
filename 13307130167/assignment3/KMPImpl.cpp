/**
 * @author whimsycwd
 * @date 2014.10.1
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;

    public :
        KMPImpl(string pattern) {
        }

        virtual int find(string text) {
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        }
};
