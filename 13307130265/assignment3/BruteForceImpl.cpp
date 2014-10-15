/**
 * @author whimsycwd
 * @date   2014.10.1
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher {

	private :
		string pattern;


	public :
		explicit BruteForceImpl(const string& _pattern) {
			pattern = _pattern;
		}

		virtual int find(string text) {
			for (int i = 0; i < (int) text.size(); ++i) {
				if (i + pattern.size() > text.size()) break;
				if (pattern == text.substr(i, pattern.size())) return i;
			}
			return NOT_FOUND;
		}

		virtual ~BruteForceImpl() {

		}
};



