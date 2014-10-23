/*
*	Copyright (C)	Lyq root#lyq.me
*	File Name     : KarpRabinImpl.cpp
*	Creation Time : 2014/10/13 21:39:05
*	Environment   : Ubuntu 14.04-64bit
*	Hompage       : http://www.lyq.me
*/

#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher 
{
private :
	string pattern;
    int len_pattern;
	int hash_pattern;
	const int w;
	const int big_number;
	int most_significant_w;

public :
	KarpRabinImpl() : w(26),big_number(20009)
	{
		len_pattern = 0;
		hash_pattern = 0;
		most_significant_w = 0;
	}	
	explicit KarpRabinImpl(const string & pattern0) : w(26),big_number(20009) 
	{
		pattern = pattern0;
		len_pattern = pattern.length();
		most_significant_w = 1;
		for (int i = 0; i < len_pattern; i++)
		{
			most_significant_w = most_significant_w * w % big_number;
		}
		hash_pattern = hash(pattern, 0, -1);
    } 
    
	int hash(const string &str, int start, int pre_hash)
	{
		long long hash = 0;
		if (pre_hash == -1)
		{
			for (int i = 0; i < len_pattern; i++)
			{
				hash = (hash + (long long)str[i+start]) * w % big_number;
			}
			return (int)hash;
		}else
		{
			hash = (pre_hash - (int)str[start-1] * most_significant_w) % big_number;	 
			while (hash < 0) hash = (hash + big_number) % big_number;
			hash = (hash + (int)str[start-1+len_pattern]) * w % big_number;
			return (int)hash;
		}
	}
    
    virtual int find(string text) 
	{
		int len_text, hash_text, pos;
		
		len_text = text.length();
		hash_text = -1;
		pos = -1;
		for (int i = 0; i < len_text-len_pattern+1; i++)
		{
			hash_text = hash(text, i, hash_text);
			if (hash_text != hash_pattern) continue; 
			
			pos = i;
			for (int j = 0; j < len_pattern; j++)
			{
				if (text[i+j] == pattern[j]) continue;
				pos = -1;
				break;
			}
			if (pos == i) break;
		}
		return pos;
    }

    virtual ~KarpRabinImpl() 
	{
    }
};
