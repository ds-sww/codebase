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
		vector<int> pattern_next;
		string pattern;

	public :
		KMPImpl(const string &_pattern) {
			pattern = _pattern;
			pattern_next.resize(pattern.size());
			int now = 0;
			for (int i = 1; i < pattern.size(); ++i) {
				while (now && pattern[i] != pattern[now]) now = pattern_next[now-1];
				if (pattern[i] == pattern[now]) ++now;
				pattern_next[i] = now;
			}
		}

		virtual int find(string text) {
			int now = 0;
			for (int i = 0; i < text.size(); ++i) {
				while (now && pattern[now] != text[i]) now = pattern_next[now-1];
				if (text[i] == pattern[now]) {
					++now;
					if (now == pattern.size()) return i - pattern.size() + 1;
				}
			}
			return NOT_FOUND;
		}

		virtual ~KMPImpl() {
		}
};
