/**
 * @author ChenYuxin
 * @date 2014.10.15
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
        int lenPattern;
		int *pre;

    public :
        KMPImpl(string pattern) {
			this->pattern = pattern;
			lenPattern = pattern.length();

			pre = new int[lenPattern];

			pre[0] = -1;
			for(int i = 1, j = -1; i < lenPattern; i++)
			{
				for(; j != -1 && pattern[i] != pattern[j + 1]; j = pre[j])
				{
				}

				if(pattern[i] == pattern[j + 1])
				{
					j++;
				}
				pre[i] = j;
			}
        }

        virtual int find(string text) {
        	int lenText = text.length();

			int i, j;
			for(i = 0, j = -1; i < lenText; i++)
			{
				for(; j != -1 && text[i] != pattern[j + 1]; j = pre[j])
				{
				}

				if(text[i] == pattern[j + 1])
				{
					j++;
				}

				if(j == lenPattern - 1)
				{
					return i - lenPattern + 1;
				}
			}
			
			//if(j != -1) return lenText - j;

            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
        }
};
