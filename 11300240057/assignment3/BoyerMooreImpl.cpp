/**
 * @author whimsycwd
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
        const static int CHARS_NUM = 256;
        
        int badCharShift[CHARS_NUM];    // 下标是字母， 内容是放生不匹配时下次pattern中出现该字母的偏移量
        vector<int> goodSuffixShift;    // 下标范围是0..pattern.size() - 1, 当 i+1..pattern.size() - 1 match的时候的至少偏移量

        void preprocessBadCharShift() {
            for (int i = 0; i < CHARS_NUM; ++i) {
                badCharShift[i] = pattern.size();
            }
            // pattern[pattern.size() - 1] 不能算，因为前提条件是发生不匹配，算了之后，
            // 整个badCharShift等于无效
            for (int i = 0; i < pattern.size() - 1; ++i) {
                badCharShift[pattern[i]] = pattern.size() -1 - i;                
            }
        }
        void preprocessGoodSuffixShift() {
            for (int i = 0; i < pattern.size(); ++i) {
                goodSuffixShift[i] = pattern.size() - i;  
            }          
       
            //  pattern[i] != pattern[j - (pattern.size() - 1 - pSub)] 
            //  pattern[i+1 .. pattern.size() - 1]  == pattern[ ... ]
            for (int i = 0; i < pattern.size() - 1; ++i) {
                for (int j = pattern.size() - 2; j >= 0; --j) {
                    int pSub = pattern.size() - 1;
                
                    bool isMatch = true;
                    while (isMatch && 
                            pSub >i && j - ((int) pattern.size() - 1 - pSub) >= 0) {
                    //    printf("%c %c\n", pattern[pSub], pattern[j -((int) pattern.size() - 1 - pSub)]); 
                        isMatch &= pattern[pSub] == pattern[j - ((int) pattern.size() - 1 - pSub)];
                        --pSub;
                    }
                    if (j - ((int) pattern.size() - 1 - pSub) >= 0) {
                        isMatch &= pattern[i] != pattern[j - ((int) pattern.size() - 1 - pSub)];
                    }
                    if (isMatch) {
                        goodSuffixShift[i] = pattern.size() -1 - j;      
                        break;
                    }
                    //  cout << isMatch << endl;   
                }
            }
        }

    public :

        BoyerMooreImpl(string pattern) {

            this->pattern = pattern;           
            preprocessBadCharShift(); 
            
            goodSuffixShift = vector<int>(pattern.size(), 0);
            preprocessGoodSuffixShift();
            
            /*            
            printf("%d %d %d %d\n", badCharShift['A'], badCharShift['C'], badCharShift['G'], badCharShift['T']);

            for (int i = 0; i < pattern.size(); ++i) {
                printf("%d ", goodSuffixShift[i]);
            }
            printf("\n");
            */
        }

        virtual int find(string text) {
            if (text.size() < pattern.size()) {
                return NOT_FOUND;
            }

            int pText = 0;
            while (pText <= text.size() - pattern.size()) {
                int pPattern = pattern.size() - 1;
                while (pPattern >= 0 && text[pText + pPattern] == pattern[pPattern]) {
                    --pPattern;
                }

                if (pPattern == -1) {
                    return pText;
                }
                
                // now,  pPattern >= 0 && text[pText + pPattern] != pattern[pPattern]
                pText += max(goodSuffixShift[pPattern], badCharShift[text[pText + pPattern]] - ((int)pattern.size()-1 - pPattern)); 
                // cout << pText << " " << pPattern << " "<< pattern[pPattern] << endl;
            }

            return NOT_FOUND;
        }

        virtual ~BoyerMooreImpl() {
        }
};
/*
int main() {
    BoyerMooreImpl impl("CGTCTCTC");

    cout << impl.find("CGTAGCGTCTCTCATATGTCATGC") << endl;
    return 0;
}
*/

