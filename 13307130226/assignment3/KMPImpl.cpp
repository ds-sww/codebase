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
		int pl;
		int next[2000000];

    public :
        KMPImpl(string pattern) {
			this->pattern = pattern;
			pl = pattern.length();
			int j = 0;
			next[0] = 0;
			for(int i=2;i<pl;i++){
				while(j>0 && pattern[j]!=pattern[i])
					j = next[j];
				if (pattern[j+1] == pattern[j])
					j++;
				next[i] = j;
			}
        }

        virtual int find(string text) {
			int j = 0;
			int tl = text.length();
			for(int i=0;i<tl;i++){
				while(j>0 && text[i]!=pattern[j])
					j = next[j];
				if(text[i]==pattern[j])
					j++;
				if(j == pl){
					return i-j+1;
					//printf("get %d\n",i-j+1);
					j = next[j];
				}
			}
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        }
};
