/**
 * @author aixile
 * @date 2014.10.14
 */


#include<string>
#include<cstdio>
#include<iostream>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
		int *fail;
    public :
        KMPImpl(string pattern):pattern(pattern){
			fail=new int[pattern.length()+10];
			fail[0]=-1;
			for(int i=1,j=0;i<pattern.length();i++){
				j=fail[i-1];
				while(j>=0&&pattern[i]!=pattern[j+1])	j=fail[j];
				if(pattern[i]==pattern[j+1])	fail[i]=j+1;
				else 	fail[i]=-1;
			}
        }

        virtual int find(string text) {
			int j=-1;
			for(int i=0;i<text.length();i++){
				while(j>=0&&pattern[j+1]!=text[i]){
					j=fail[j];
				}
				if(pattern[j+1]==text[i])	j++;
				if(j+1==pattern.length())	return i-j;
			}
			return NOT_FOUND;
        }

        virtual ~KMPImpl() {
			delete fail;
        }
};


