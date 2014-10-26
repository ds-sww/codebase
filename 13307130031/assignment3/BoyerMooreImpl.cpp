/**
 * @author aixile
 * @date   2014.10.14
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
		int *phi,*delta,sz;

		bool is_prefix(string &s,int pos){
			for(int i=0;i<sz-pos;i++){
				if(s[i]!=s[pos+i])	return 0;
			}
			return 1;
		}

		int suffix_length(string &s,int pos){
			int i=0;
			for(;(s[pos-i]==s[sz-1-i])&&i<pos;i++);
			return i;
		}

    public :

        BoyerMooreImpl(string pattern):pattern(pattern){
			
			phi=new int[256];
			sz=pattern.length();
			for(int i=0;i<256;i++){
				phi[i]=sz;
			}
			for(int i=0;i<sz;i++){
				phi[(pattern[i])]=sz-i-1;
			}

			delta=new int[sz+10];
			for(int p=sz-1,last=sz-1;p>=0;p--){
				if(is_prefix(pattern,p+1))	last=p+1;
				delta[p]=last+sz-1-p;
			}
			for(int p=0;p<sz-1;p++){
				int slen=suffix_length(pattern,p);
				if(pattern[p-slen]!=pattern[sz-1-slen]){
					delta[sz-1-slen]=sz-1-p+slen;
				}
			}
        }

        virtual int find(string text) {
			int idx=pattern.length()-1,k=1,sz2=text.length();
			if(sz>sz2)	return NOT_FOUND;
			while(idx<sz2){
				k=sz-1;
				while(k>=0&&text[idx]==pattern[k])	k--,idx--;
				if(k<0)	return idx+1;
				idx+=max(phi[text[idx]],delta[k]);
			}
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
			delete phi;
			delete delta;
        }
};

