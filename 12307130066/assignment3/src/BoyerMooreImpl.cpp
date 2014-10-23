/**
 * @author Xuan Yuan
 * @date   2014.10.2
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
    int[27] characterShift; //包括26个小写字母与' '（空格）
    int* suffixShift;   //长度应与pattern相同

public :

    BoyerMooreImpl(const string & p) {
        this->pattern = p;
        
    }

    virtual int find(string text) {
        return NOT_FOUND;
    }

    virtual ~BoyerMooreImpl() {
    }
    
};






