/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>

#include "Matcher.h"

using namespace std;

#define Rehash(a,b,h) ((((h) - (a) * d) << 1) + (b))

class KarpRabinImpl : public Matcher {

    private :

        string pattern;

    public :

        explicit KarpRabinImpl(const string & pattern) {
            this -> pattern = pattern;
        }

        virtual int find(string text) {
            if (text.size() < pattern.size())
                return NOT_FOUND;

            int d,i;
            for (d = i = 1; i < pattern.size(); i++)
                d = d << 1;

            int hp,ht;
            for (hp = ht = i = 0; i < pattern.size(); i++){
                hp = (hp << 1) + pattern[i];
                ht = (ht << 1) + text[i];
            }

            int j;
            for (j = 0; j <= text.size() - pattern.size(); j++){
                if (hp == ht){
                    for (i = 0; i < pattern.size() && pattern[i] == text[i + j]; i++) ;
                    if (i == pattern.size()) return j;
                }
                ht = Rehash(text[j], text[j + pattern.size()], ht);
            }
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
