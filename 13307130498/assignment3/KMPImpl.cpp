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
        int len;
        int *next;
    public :
        KMPImpl(string pattern) {
        	this->pattern = pattern;
        	len = pattern.length();
        	next = new int [len];
        	int i,j;
        	i=0;
        	next[i] = -1;
        	next[i+1] = 0;
        	for(i=1;i<len;i++){
        		j=i;
        		while(j>=1){
        			j = next[j];
        			if(pattern[j] == pattern[i]){
						next[i+1] = j+1;
						break;
					}	
        		}
        		next[i+1] = 0;
        }

        virtual int find(string text) {
        	int length = text.length();
        	int i,j;
        	for(i=0;i+len <= length;){
        		for(j=0;j < len;j++){
        			if(pattern[j] != text[i+j])break;
        		}
        		if(j == len)break;
        		i = j-next[j];
        	}
        	if(j == len)return i;
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        }
        
        
};
