/**
 * @author liliang
 * @date 2014.10.11
 */

#include<iostream>
#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private : 
        string pattern;
		int *Next;
		int len;
    public :

        KMPImpl(string pattern) {

			this->pattern = pattern;

			len = pattern.size();

			Next = new int[len + 10];

			Next[0] = -1;
			for (int i = 1; i < len; i++)
			{
				int j = i - 1;
				Next[i] = -1;
				while (j != -1)
				{
					j = Next[j];
					if (pattern[j + 1] == pattern[i])
					{
						Next[i] = j + 1; break;
					}
				}
			}

		//	for (int i = 0; i < len; i++)
		//		cout << pattern[i];
		//	cout << endl;
		//	for (int i = 0; i < len; i++)
		//		cout << Next[i] << " ";
		//	cout << endl;

        }

        virtual int find(string text) {
			int n = text.length();
			int j = -1;
			for (int i = 0; i < n; i++)
			{
				while ((j != -1) && (pattern[j + 1] != text[i])) j = Next[j];
				if (pattern[j + 1] == text[i]) ++j;
				if (j == len - 1) 
				{
					return i - len + 1; 
				}
			}
            return NOT_FOUND; 
        }

        virtual ~KMPImpl() {
			delete[]Next;
        }
};


