/**
 * @author whimsycwd
 * @date 2014.10.1
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
private:
	string pattern;
	int length;
	int *t;

public:
	void compile(string pattern){
		t = new int[length];
		for (int i = 0; i < length; i++)
			t[i] = 0;
		for (int i = 1; i < length; i++){
			if (pattern[t[i - 1]] == pattern[i]){
				t[i] = t[i - 1] + 1;
			}
			else{
				if (t[i - 1] != 0){
					if (pattern[t[t[i - 1] - 1]] == pattern[i])
						t[i] = t[t[i - 1] - 1] + 1;
				}
			}
		}
	}
	KMPImpl(string pattern) {
		this->pattern = pattern;
		length = pattern.length();
		compile(pattern);
	}

	virtual int find(const string text) {
		int i, j;
		int already = 0;
		for (i = 0, j = 0; i < text.length();){
			if (text[i] == pattern[j]){
				already++;
				i++;
				j++;
				if (j == length)
					return i - length;
			}
			else{
				if (already != 0){
					j = j - already + t[j - 1];
					already = j;
				}
				else{
					already = 0;
					i++;
					j = 0;
				}
			}
		}
		return -1;
	}

        virtual ~KMPImpl() {
        }
};
