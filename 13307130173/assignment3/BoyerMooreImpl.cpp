#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "Matcher.h"
#define maxalpha 256
using namespace std;
class BoyerMooreImpl : public Matcher {
    
    private :
        string pattern;       
        int bc[maxalpha],*gs,*suff;
        void makesuffix(string s,int len)
        {
            suff[len-1]=len;
            int r;
            int l=len-1;
            for (int i=len-2;i>=0;i--)
            {
                if (i>l && suff[i+len-1-r]<=i-l) suff[i]=suff[i+len-1-r];
                    else {
                            if (i<l) l=i;
                            r=i;
                            while (l>=0 && s[l]==s[l+len-1-r]) l--;
                            suff[i]=r-l;
                         }
            }
        }
        void makebadchar(string s,int len)
        {
            for (int i=0;i<maxalpha;i++) bc[i]=len;
            for (int i=0;i<len-1;i++) bc[s[i]]=len-i-1;
        }
        void makegoodsuffix(string s,int len)
        {
            gs[len-1]=1; 
            int lastprefix=1;
            for (int i=len-2;i>=0;i--)
            {
                if (suff[len-2-i]==len-1-i) lastprefix=i+1;
                gs[i]=lastprefix+len-1-i;
            }
            for (int i=1;i<len-1;i++)
            {
                int tlen=suff[i];
                if (tlen>0 && s[i-tlen]!=s[len-1-tlen]) gs[len-1-tlen]=len-1-i+tlen;
            }   
        }
        int bm(string T,int Tlen,string P,int Plen)
        {
            int j;
            for (int i=Plen-1;i<Tlen;i+=max(gs[j],bc[T[i]]))
            {        
                    for (j=Plen-1;j>=0 && P[j]==T[i];i--,j--);
                    if (j<0) return i+1;
            }
            return -1;
        }    

    public :

        BoyerMooreImpl(string pattern) {
            this->pattern=pattern;
            gs=new int[pattern.size()];
            suff=new int [pattern.size()];
            makesuffix(pattern,pattern.size());
            makebadchar(pattern,pattern.size());
            makegoodsuffix(pattern,pattern.size());

        }

        virtual int find(string text) {            
            return bm(text,text.size(),pattern,pattern.size());
        }
       
        virtual ~BoyerMooreImpl() {
            delete[]gs;
            delete[]suff;
        }
};

