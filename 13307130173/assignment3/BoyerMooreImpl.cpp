
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
        int bc[maxalpha],*gs;

        void makebadchar(string s,int len)
        {
            for (int i=0;i<maxalpha;i++) bc[i]=len;
            for (int i=0;i<len-1;i++) bc[s[i]]=len-i-1;
        }
        int suffixsame(string s,int pos,int len)
        {
            int i;
            for (i=0;i<pos && s[len-1-i]==s[pos-i];i++);
            return i;
        }
        int isprefix(string s,int len,int pos)
        {
            for (int i=0;i<len-pos;i++) if (s[i]!=s[pos+i]) return 0;
            return 1;
        }
        void makegoodsuffix(string s,int len)
        {
            gs[len-1]=1; //end of string no prefix=suffix of t xt x doesn't match string should move len right
            int lastprefix=1;
            for (int i=len-2;i>=0;i--)
            {
                if (isprefix(s,len,i+1)) lastprefix=i+1; //p not match
                gs[i]=lastprefix+len-1-i;
                // i..i+len-1-j   j..len-1   i+len-1-j+lastprefix
            }
            //case 2    i not match [lastprefix..len-1]=[0..len-1-lastprefix];
            for (int i=1;i<len-1;i++)
            {
                int tlen=suffixsame(s,i,len);
                if (tlen>0 && s[i-tlen]!=s[len-1-tlen]) gs[len-1-tlen]=len-1-i+tlen;
            }   
            //len-1-(i-tlen)  len-1-(len-1-tlen)  len-1-i+i'+len-1-j   j=len-1-tlen;
            //case 1    i not match [i-tlen+1..i]=[len-tlen..len-1]
            //   yt    xt    so the position of x must be <len-1 & >0 in order to make room for y;
        }
        int bm(string T,int Tlen,string P,int Plen)
        {
            int j;
            for (int i=Plen-1;i<Tlen;i+=max(gs[j],bc[T[i]]))
            {        
                    for (j=Plen-1;j>=0 && P[j]==T[i];i--,j--);
                    if (j<0) return i+1;
            }
            //   for example
            //...............xbbad   Text
            //       tqxbbadtybbad   Pattern
            //             tqxbbadtybbad
            //               j   Plen-1
            //         bc[T[i]]
            //  i+Plen-1-j+   steps to move
            //steps to move=  the nearest two "x"s the distance is
            //  bc[T[i]]-(Plen-1-j)
            //so the updated position of i is i+Plen-1-j+bc[T[i]]-(Plen-1-j)=i+bc[T[i]];   and the updated initial position of j should be Plen-1   from right to left;
            return -1;
        }    

    public :

        BoyerMooreImpl(string pattern) {
            this->pattern=pattern;
            gs=new int[pattern.size()];
            makebadchar(pattern,pattern.size());
            makegoodsuffix(pattern,pattern.size());

        }

        virtual int find(string text) {            
            return bm(text,text.size(),pattern,pattern.size());
        }
       
        virtual ~BoyerMooreImpl() {
            delete[]gs;
        }
};

