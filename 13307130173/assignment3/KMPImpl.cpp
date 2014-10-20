#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        int *next;
    public :
        KMPImpl(string pattern) {
            this->pattern=pattern;
            next=new int[pattern.size()];          
            next[0]=-1; 
            int j=-1;
            for (int i=1;i<pattern.size();i++)
            {
                while (j>-1 && pattern[j+1]!=pattern[i]) j=next[j];
                if (pattern[j+1]==pattern[i]) j++;
                next[i]=j;
            }
        }

        virtual int find(string text) {
            if (text.size()<pattern.size()) return NOT_FOUND;
            int j=-1;
            for (int i=0;i<text.size();i++)
            {
                while (j>-1 && text[i]!=pattern[j+1]) j=next[j];
                if (text[i]==pattern[j+1]) j++;
                if (j==pattern.size()-1) return i-pattern.size()+1;              
            }
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
           delete[] next;
        }
};
