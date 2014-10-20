/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : BruteForceImpl.cpp
*	Creation Time : 2014/10/13 21:21:39
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Matcher.h"

using namespace std;

class BruteForceImpl : public Matcher 
{
private :
	string pattern;
	int len_pattern;

public :
	explicit BruteForceImpl(const string& pattern0) 
	{
		pattern = pattern0;
		len_pattern = pattern.length();
	}
	
	virtual int find(string text) 
	{
		int len_text = text.length();
		int is_find = -1;

		for (int i = 0; i < len_text-len_pattern+1; i++)
		{
			is_find = i;
			for (int j = 0; j < len_pattern; j++)
			{
				if (pattern[j] == text[i+j]) continue;
				is_find = -1;
				break;
			}
			if (is_find > -1) break;
		}

		return is_find;
    }
        
    virtual ~BruteForceImpl() 
	{
            
    }
};



