/**
 * @author whimsycwd
 * @date 2014.10.1
 */


#include<string>
#include<vector>

#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private :
        string pattern;
        const int SIZE = 100;

    public :
        KMPImpl(string pattern) {
            this -> pattern = pattern;
        }

        void preprocessing(string p, int m, int Next[]) {
            for (int i = 0, j = Next[0] = -1; i < (m - 1); ) {
                for (; j > -1 && p[i] != p[j]; )
                    j = Next[j];
                i++;
                j++;
                if (p[i] == p[j]) Next[i] = Next[j];
                else Next[i] = j;
            }
        }

        virtual int find(string text) {
            if (text.size() < pattern.size())
                return NOT_FOUND;

            int i,j,Next[SIZE];
            preprocessing(pattern, pattern.size(), Next);
            for (i = j = 0; j < text.size(); ) {
                for (; i > -1 && pattern[i] != text[j]; )
                    i = Next[i];
                i++;
                j++;
                if (i >= pattern.size())
                    return (j - i);
            }
            return NOT_FOUND;
        }

        virtual ~KMPImpl() {
        }
};
