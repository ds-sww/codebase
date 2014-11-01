/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {

	private :
		const static int mod = (int) 1e9 + 7;
		const static int seed = 2007;

		string pattern;
		vector<int> mypow;
		vector<int> hash;
		int get_hash(int i, int j, int n) {
			return (long long) (hash[j] - hash[i-1] + mod) % mod * mypow[n-j] % mod;
		}
	
	public :

			explicit KarpRabinImpl(const string & _pattern) {
				pattern = _pattern;
			} 

			virtual int find(string text) {
				if (text.size() < pattern.size()) return NOT_FOUND;
				
				mypow.resize(text.size()+1);
				hash.resize(text.size()+1);
				
				mypow[0] = 1;
				for (int i = 1; i <= text.size(); ++i) mypow[i] = (long long) mypow[i-1] * seed % mod;
				
				int target_hash = 0;
				for (int i = 0; i < pattern.size(); ++i) {
					target_hash = (target_hash + (long long) pattern[i] * mypow[i]) % mod;
				}
				
				target_hash = (long long) target_hash * mypow[text.size() - pattern.size()] % mod;
				
				for (int i = 0; i < text.size(); ++i) {
					hash[i+1] = (hash[i] + (long long) text[i] * mypow[i]) % mod;
				}
				
				for (int i = 0; i < text.size(); ++i) {
					if (i + pattern.size() > text.size()) break;
					if (get_hash(i+1, i+pattern.size(), text.size()) == target_hash) return i;
				}
				
				return NOT_FOUND;
			}

			virtual ~KarpRabinImpl() {
			}
};
