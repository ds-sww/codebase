/**
 * @author 13307130278_liliang
 * @date   2014.10.15
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
		int len;
		int bad_move[130];
		int *good_move;
		int *Next;
		int Max(int a, int b)
		{
			if (a > b) return a; return b;
		}
    public :

        BoyerMooreImpl(string pattern) {
			this->pattern = pattern;
			len = pattern.size();
			memset(bad_move, 0, sizeof(bad_move));
			for (int i = 0; i < 30; i++)bad_move[i] = len;
			for (int i = 0; i < len; i++)
			{
				bad_move[pattern[i]] = len - 1 - i;
			}
			Next = new int[len + 10];
			good_move = new int[len + 10];
			Next[len - 1] = len;
			for (int i = len-2; i>=0; i--)
			{
				int j = i+1;
				Next[i] = len;
				while (j != len)
				{
					j = Next[j];
					if (pattern[i] == pattern[j - 1])
					{
						Next[i] = j - 1;
						break;
					}
				}
			}
			for (int i = 0; i < len; i++)
				good_move[i] = -1;
			for (int i = 0; i < len; i++)
				good_move[len - Next[i]] = i;
        }

        virtual int find(string text) {
			int n = text.size();
			int j = 0;
			while (j <= n - len)
			{
				int i;
				for (i = len - 1; i >= 0 && (pattern[i] == text[i + j]); --i);
				if (i < 0)
					return j;
				int k = bad_move[pattern[i]] - (len - 1 - i);
				if (good_move[len - i - 1] == -1)
					k = Max(k, j + len - (len - Next[0]));
				else k = Max(k, i + 1 - good_move[len - i - 1]);
				j += k;
			}
            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};

