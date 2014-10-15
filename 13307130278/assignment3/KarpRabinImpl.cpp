/**
 * @author liliang
 * @date   2014.10.12
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
		int len,nlen;
		int hashnum;
		
    public :

        explicit KarpRabinImpl(const string & pattern) {
			this->pattern = pattern;
			nlen = pattern.size();
			len = nlen;
			if (len > 28)
				len = 28;
			hashnum = 0;
			int mod = 1 << (len-1);
			for (int i = 0; i <len; i++)
				hashnum = ((hashnum << 1)+pattern[i]);
        } 
        
        virtual int find(string text) {
			int textnum = 0, n = text.size();
			int mod = 1 << (len - 1);
			int num = 1;
			for (int i = 1; i < len; i++)
				num = num << 1;
			for (int i = 0; i < n ; i++)
			{
				if (i <= len - 1)
				{
					textnum = ((textnum << 1) + text[i]);
				}
				if (i < len - 1)continue;
				if (textnum == hashnum)
				{
					int check = 1;
					int j = i - len + 1, k = 0;
					while ((k < nlen)&&(j<n))
					{
						if (pattern[k] != text[j]) { check = 0; break; }
						++k; ++j;
					}
					if ((k < nlen) && (j == n)) check = 0;
					if (check) return (i - len + 1);
				}
				if (i == n - 1) break;
				textnum = (((textnum - (text[i - len + 1]*num)) << 1) + text[i + 1]);
			}
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
