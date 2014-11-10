/**
 * @author ChenYuxin
 * @date   2014.10.15
 *
 * help to understand KMP
 * Automata with only one pattern. 
 */

#include<string>
#include<vector>
#include<iostream>
#include<cstring>

#include "Matcher.h"

using namespace std;

class AutomataImpl : public Matcher {
    private : 
		const static int CHAR_NUMBER = 26;
		const static int NOT_FOUND = -1;
		string pattern;
		int lenPattern;
		int (*child)[CHAR_NUMBER]; ///////// unskilled

		void preprocess()
		{
			for(int i = 0; i < lenPattern; i++)
			{
				child[i][pattern[i] - 'a'] = i + 1;
			}

			for(int i = 1, cur = 0; i < lenPattern; i++)
			{
				for(int j = 0; j < CHAR_NUMBER; j++)
				{
					if(!child[i][j]) child[i][j] = child[cur][j];
				}
				cur = child[cur][pattern[i - 1] - 'a'];
			}
		}

	public :
        AutomataImpl(string pattern) 
        {
            this->pattern = pattern;
            lenPattern = pattern.length();

			child = new int[lenPattern + 1][CHAR_NUMBER];
            
            memset(child, 0, lenPattern * CHAR_NUMBER * sizeof(int));

            preprocess();
        }

        virtual int find(string text) 
        {
        	int lenText = text.length();

        	for(int i = 0, cur = 0; i < lenText; i++)
			{
				cur = child[cur][text[i] - 'a'];

				if(cur == lenPattern) return i - lenPattern + 1;
			}

			return NOT_FOUND;
        }

        virtual ~AutomataImpl() 
        {
            delete[] child; //////// unskilled
        }
};

