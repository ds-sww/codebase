/**
 * @author chiyahoho
 * @date   2014.10.13
 */
#include <iostream>
#include <string>
#include "Matcher.h"
using namespace std;
typedef long long ll;

class KarpRabinImpl : public Matcher {
    
    private :
        string pattern;
        static const ll base=307,mo=1000000007;
        
    public :
        explicit KarpRabinImpl(const string & pattern) {
            this->pattern=pattern;
        } 
        
        virtual int find(string text) {
            int n=text.length(),m=pattern.length();
            if (n<m) return NOT_FOUND;
            int l=0,r=m;
            ll pat=0,one=1,hl=0,hr=0;
            for (int i=0;i<m;i++){
                pat=(pat*base+pattern[i])%mo;
                hr=(hr*base+text[i])%mo;
                one=one*base%mo;
            }
            for (;l<=n-m;hl=(hl*base+one*text[l++])%mo,hr=(hr*base+text[r++])%mo)
                if (hr==(pat+hl)%mo){
                    int flag=1;
                    for (int i=0;i<m;i++) if (pattern[i]!=text[l+i]) {flag=0;break;}
                    if (flag) return l;
                }
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};