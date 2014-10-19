/**
 * @author sunqinzheng
 * @date   2014.10.13
 */
#include <string>
#include "Matcher.h"
using namespace std;

#define BASE 137LL
#define MOD 1000000007LL

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
        long long phash;
        long long step;

        static long long quickPow(long long b, int exp);

    public :

        KarpRabinImpl(const string & p);
        
        int find(string text);

        ~KarpRabinImpl();
};
