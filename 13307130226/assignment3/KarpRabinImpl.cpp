/**
 * @author qzane
 * @date   2014.10.2
 * bad character shift 和 good suffix shift 都是偏移的必要条件
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Matcher.h"

using namespace std;


class KarpRabinImpl : public Matcher {
    
    private :
        string pattern;
		int length;
		unsigned int pattern_hash;
		unsigned int mask;
		
		unsigned int hash(const string& text){
			unsigned int Hash;
			Hash = 0;
			for(int i=0;i < length;i++){
				Hash = ((Hash<<1)+text[i]);
			}
			return (Hash & mask);
		}
		unsigned int re_hash(char a,unsigned int hs){
			return ((hs << 1) + a) & mask;			
		}

    public :

        KarpRabinImpl(const string& pattern) {
			(*this).pattern = pattern;
			length = pattern.size();
			mask = (1<<length)-1;
			pattern_hash = hash(pattern);
        }

        virtual int find(string text) {
			bool Find = false;
			unsigned text_hash;
			if(text.size() < length)
				return NOT_FOUND;
			text_hash = hash(text);
			for(int pos=0;pos <= text.size()-length;pos++){
				if(text_hash == pattern_hash)
					for(int i=0;i<length;i++)
						if(text[pos+i] != pattern[i])
							break;
						else if(i == length-1)
							return pos;
				text_hash = re_hash(text[pos+length],text_hash);
			}
			
			
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
/*
int main(){
	string o,m;
	cin >> o;
	cin >> m;
	BoyerMooreImpl  A(o);
	cout << A.find(m);
	while(1){
		cin >> m;
		cout << A.find(m);
	}
	return 0;
}*/

