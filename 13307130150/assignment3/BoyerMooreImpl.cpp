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

        BoyerMooreImpl(string pattern) {
            this->pattern=pattern;
        }
        
        int MAX(int a,int b) {if (a>b) return a; else return b;} 

        void suffixes(string &pattern,int *suff){
            int m=pattern.size();
            int f,g;
            suff [m-1]=m;
            g=m-1;
            for (int i=m-2; i>=0; i--)
                if (i>g && suff[i+m-1-f]<i-g)
                    suff[i]=suff[i+m-1-f];
                else
                {
                    if (i<g) g=i;
                    f=i;
                    while (g>=0 && pattern[g]==pattern[g+m-1-f])
                        g--;
                    suff[i]=f-g;
                }
        }    // suff record the max suffix of pattern and pattern before i

        void preBMGs(string &pattern,int *shift2) {
            int m=pattern.size();
            int *suff=new int [m];
            int j=0;
            suffixes(pattern,suff);
            for (int i=0;i<m; i++)
                shift2[i]=m;   //init case3 move len
            for (int i=m-1; i>=-1; i--)   
                if (i==-1 || suff[i]==i+1)
                    while (j<m-1-i)
                    {
                        if (shift2[j]==m)
                            shift2[j]=m-1-i;
                        j++;
                    }
            for (int i=0; i<=m-1; i++)
                shift2[m-1-suff[i]]=m-1-i;
        }

        virtual int find(string text) {
            int len1=text.size();
            int len2=pattern.size();
            if (len1<len2) return NOT_FOUND;
            
            int Asize=256;
            int shift1[Asize];
            int *shift2=new int [len2];
            for (int i=0; i<Asize; i++)
                shift1[i]=len2;
            for (int i=0; i<len2-1; i++)
                shift1[pattern[i]]=len2-i-1;// bad character

            preBMGs(pattern,shift2);// good suffix

            int i,j=0;
            while (j<=len1-len2)
            {
                for (i=len2-1; i>=0&&pattern[i]==text[i+j]; i--);
                if (i<0) return j;
                else 
                    j=j+MAX(shift2[i],shift1[text[i+j]]-len2+1+i);
            }
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};

