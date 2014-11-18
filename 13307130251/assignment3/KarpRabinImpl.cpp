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
        

    public :

        explicit KarpRabinImpl(const string & pattern) {
        } 
        
        virtual int find(string text) {
            return NOT_FOUND;
        }

        virtual ~KarpRabinImpl() {
        }
};
