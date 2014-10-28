/**
 * @author whimsycwd
 * @date   2014.10.1
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;

class BruteForceImpl {
    
    private :
        string pattern;


    public :
        BruteForceImpl(const string& pattern) {
            this->pattern = pattern;  
        }

        void printAns(const vector<int> vec) {
            if (vec.size() == 0) {
                printf("-1\n");
            } else {
                for (int i = 0; i < vec.size(); ++i) {
                    printf("%d ", vec[i]);
                }
                printf("\n");
            }
        }

        void find(const string& text) {
            vector<int> vec;
            if (text.size() < pattern.size()) {
               printAns(vec);
               return;
            }
            // must `<=` instead of `<`
            for (int i = 0; i <= text.size() - pattern.size(); ++i) {
                
                bool isMatch = true;
                int j = 0;
                while (isMatch && j < pattern.size()) {
                    isMatch &= text[i+j] == pattern[j];
                    ++j;
                }
                
                if (isMatch) {
                    vec.push_back(i);
                }
            }
            printAns(vec);
        }
};

int main() {
    string text;
    string pattern;
    while (cin >> text >> pattern) {
        BruteForceImpl impl(pattern);
        impl.find(text);
    }
    return 0;
}


