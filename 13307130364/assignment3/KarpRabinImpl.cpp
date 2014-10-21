/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher {
    
    private :

        string pattern;
		long hvalue;
		int length;

    public :
		long khash(const char *s)
		{
			int len = length;
			long hash = 0;
			unsigned char *p = (unsigned char *)(s);
			do
			{
				hash = (hash << 1) + *p++;
			} while (--len);
			return hash;
		}
		int compare(const char* a,const char* p){
			for (int i = 0; i < length; i++)
			if (a[i] != p[i]){
				return 0;
			}
			return 1;
		}


        explicit KarpRabinImpl(const string & pattern) {
			this->pattern = pattern;
			length = pattern.length();
			hvalue = khash(pattern.c_str());
        } 
        
        virtual int find(const string text) {
			int l = text.length();
			const char *ctext = text.c_str();
			const char *cpattern = pattern.c_str();
			for (int i = 0; i <= l - length; i++){
				if (khash(ctext+i) == hvalue)
					if (compare(ctext+i, cpattern))
						return i;
			}
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
