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
        int *next;
    public :
        KMPImpl(string pattern) {
            this->pattern=pattern; 
            int len = pattern.size()+1;  
            int j=0,i=1;  
            next = new int[len+1];  
            next[i] = 0;  
            while (i<len)  
            {  
                if (j == 0 || pattern[i-1] == pattern[j-1])  
                {  
                    i++;  
                    j++;  
                    next[i] = j;  
                }  
                else  j = next[j];  
            }  
        }

        virtual int find(string text) {
            int len1=text.size()+1;
            int len2=pattern.size()+1;
            int i=0,j=0;
            if (len1<len2) return NOT_FOUND;
            while (i < len1 && j < len2)  
            {  
                if (j == 0 || text[i - 1] == pattern[j - 1])  
                {i++; j++;}  
                else  j = next[j];  
            }  
            if (j == len2)  return i-len2;  
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
            delete [] next;
        }
};
