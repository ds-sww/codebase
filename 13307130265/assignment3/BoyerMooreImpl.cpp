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
		int bad_char_skip[257];
	public :

		BoyerMooreImpl(const string &_pattern) {
			pattern = _pattern;
		}
		
		virtual int find(string text) {
		
		
		
			for (int scan = 0; scan < 256; ++scan) {
				bad_char_skip[scan] = pattern.size();
			}
			
			int last = pattern.size()-1;
			for (int scan = 0; scan < last; scan++) {
				bad_char_skip[pattern[scan]] = last - scan;
			}
			
			int plen = pattern.size();
			int tlen = text.size();
			int s = 0;
			int t = 0;
			
			while (tlen >= plen) {
				for (int scan = last; pattern[s+scan] == text[t+scan]; --scan)
					if (scan == 0) {
						return t;
					}
				tlen -= bad_char_skip[text[t+last]];
				t += bad_char_skip[text[t+last]];
			}
			
			return NOT_FOUND;
		}

		virtual ~BoyerMooreImpl() {
		}
};

