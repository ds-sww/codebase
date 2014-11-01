/**
 * @author Minjun-Li
 * @date   2014.10.12
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <ctime>
#include "Matcher.h"
#include <fstream>

#include "BruteForceImpl.cpp"
#include "KarpRabinImpl.cpp"
#include "KMPImpl.cpp"
#include "BoyerMooreImpl.cpp"
#include "AutomataImpl.cpp"

using namespace std;


// for execution profile
// code snippet from https://github.com/arhuaco/junkcode/blob/master/emqbit-bench/bench.c
// =========== begin ============


static clock_t get_timestamp() {
    return clock();
}
// =========== end ==============


int type = 0; 
const static int CHAR_MOD = 10;

// 0 stand for BruteForceImpl

Matcher * getImpl(const string& pattern) {
    if (type == 1){
        return new BruteForceImpl(pattern);
    }
    if (type == 2) {
        return new KarpRabinImpl(pattern);
    }
    if (type == 3) {
        return new KMPImpl(pattern);
    
    }
    if (type == 4) {
        return new BoyerMooreImpl(pattern);
    }
    if (type == 5) {
        return new AutomataImpl(pattern);
    }

    return 0;
}

void find(string text, string pattern, int expect) {

    clock_t start_time = clock();
    Matcher * impl = getImpl(pattern);
    int pos = impl->find(text);
    clock_t end_time = clock();

    printf("pos :%d\texpect : %d\n", pos, expect);


    assert(pos == expect);
   // cout << pattern.size() << endl;
    string out_text = (text.size() <= 100) ? text : "Too Long";
    string out_pattern =(pattern.size() <= 100) ? pattern : "Too Long";

    
    //printf("start time : %lu\n", start_time);
    //printf("end   time : %lu\n", end_time);

    printf("text          : %s\npattern       : %s\nmatch positon : %d\nexecution time: %lfs\n\n", 
            out_text.c_str(), out_pattern.c_str() , pos, ((double) end_time - start_time) / CLOCKS_PER_SEC);
    delete impl;
}

string gen_string(int size) {
    string retStr = "";
    for (int i = 0; i < size; ++i) {
        retStr.append(1, rand() % CHAR_MOD + 'a');  // save 'z' for target ans.
    }
    // cout << retStr << endl;
    return retStr;
}

void gen_text_pattern(int text_len, int pattern_len, string& text, string& pattern) {
    text = gen_string(text_len);
    pattern = gen_string(pattern_len);
    pattern.append(1, 'z'); 
}
void test_naive() {
    
    fstream fs("genData.txt", fstream::in);

    string text;
    string pattern;
    int expect;
    while (fs >> pattern >> text >> expect) {
        // cout << text << " " <<  pattern << " "<< expect<< endl;
        find(text, pattern, expect);
    }

    fs.close();

        

} 

string repeat(string s, int n) {

    string retValue = "";
    for (int i = 0; i < n; ++i) {
        retValue += s;
    }
    return retValue;
}

void genData() {
    
    FILE * fp = fopen("genData.txt", "w");
    
    if (fp) {
        puts("open file success");
    } else {
        puts("open file fail");
        return;
    }

    string pattern = "abc";
    string text = "abdadfadfaabcdadfadfa";  // random input
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), 10);
    
    text = "adfadsabc";  // match in end of text  
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), 6);
    
    text = "abcadfadfadf"; // match in front
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), 0);
   

    // repeat 
    pattern ="aaaaa"; 
    text = "bbbccccccadfadff";
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), Matcher::NOT_FOUND);
    
    text = "aaaaaaaaaaaaaa";
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), 0);

    text = "aaaabbbbbbaaaaaaaaa";
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), 10);
    
    // long text

    
    int text_len = 100000;
    int pattern_len = 999;
    gen_text_pattern(text_len, pattern_len, text, pattern);
    text = text + pattern;
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), text_len);


    gen_text_pattern(text_len, pattern_len, text, pattern);
    text = pattern + text;
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), 0);
   

    gen_text_pattern(text_len, pattern_len, text, pattern);
    text = text + pattern + text;
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), text_len);
    
    text_len = 100000;
    pattern_len = 999;
    int repeat_time = 100;
    gen_text_pattern(text_len, pattern_len, text, pattern);
    text = repeat(text + pattern, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), text_len);


    gen_text_pattern(text_len, pattern_len, text, pattern);
    text = repeat(pattern + text, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), 0);
   

    gen_text_pattern(text_len, pattern_len, text, pattern);
    text = text + pattern + text;
    text = repeat(text, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), text_len);
   
   
     

    text_len = 100;
    repeat_time = 10000;
    text = gen_string(text_len);
    pattern = text + "z";
    text = repeat(text, repeat_time);
    text += pattern;
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), text_len * repeat_time);

    
    text_len = 100;
    repeat_time = 10000;
    text = gen_string(text_len);
    pattern = text + "z";
    text = repeat(text, repeat_time);
    text = text + pattern + text;
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), text_len * repeat_time);
    
    
    text_len = 100;
    repeat_time = 10000;
    text = gen_string(text_len);
    pattern = text + "z";
    text = repeat(text, repeat_time);
    text = text + pattern + text;
    pattern += "z";
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), Matcher::NOT_FOUND);

    //a way to kill BF
    text_len = 1000;
    repeat_time = 200;
    text.clear();
    for(int i = 0; i < text_len; i++)
    {
        text.append(1, 'a');
    }
    pattern = text + "z";
    text = repeat(text, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), Matcher::NOT_FOUND);

    //a way to kill BM
    text_len = 20000000;
    repeat_time = 2;
    text.clear();
    for(int i = 0; i < text_len; i++)
    {
        text.append(1, rand() % 10 + 'a');
    }
    pattern = text + "z";
    text = repeat(text, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), Matcher::NOT_FOUND);

    //random data with 2 charactors
    text_len = 1000;
    repeat_time = 20000;
    text.clear();
    for(int i = 0; i < text_len; i++)
    {
        text.append(1, rand() % 2 + 'a');
    }
    pattern = text + "z";
    text = repeat(text, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), Matcher::NOT_FOUND);

    //random data with 5 charactors
    text_len = 1000;
    repeat_time = 20000;
    text.clear();
    for(int i = 0; i < text_len; i++)
    {
        text.append(1, rand() % 5 + 'a');
    }
    pattern = text + "z";
    text = repeat(text, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), Matcher::NOT_FOUND);

    //random data with 24 charactors
    text_len = 1000;
    repeat_time = 20000;
    text.clear();
    for(int i = 0; i < text_len; i++)
    {
        text.append(1, rand() % 24 + 'a');
    }
    pattern = text + "z";
    text = repeat(text, repeat_time);
    fprintf(fp, "%s %s %d\n", pattern.c_str(), text.c_str(), Matcher::NOT_FOUND);

    fclose(fp);

}

int main(int argc, char * argv[]) {
   
    srand(time(NULL));
    type = -1;
    if (argc == 2) {
        if (strcmp(argv[1], "BF") == 0) {
            type = 1;
            cout << "BruteForceImpl" << endl;
        }
        if (strcmp(argv[1], "KR") == 0) {
            type = 2;
            cout << "Karp-Rabin" << endl;
        }
        if (strcmp(argv[1], "KMP") == 0) {
            type = 3;
            cout << "Knuth-Morris-Pratt" << endl;
        }
        if (strcmp(argv[1], "BM") == 0) {
            type = 4;
            cout << "Boyer-Moore" << endl;
        }
        if (strcmp(argv[1], "Automata") == 0) {
            type = 5;
            cout << "Automata" << endl;
        }
        if (strcmp(argv[1], "genData") == 0) {
            cout << "genData" << endl;
            genData();
            return 0;
        }
    }
    if (type != -1) {
        test_naive();
    } else {
        cout << "Only one parameter in (BF | KR | KMP | BM | Automata)" << endl;
    }
    
    
    return 0;
}




