#include<iostream>
#include<cstdio>

#include<algorithm>
#include<random>
#include<chrono>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<set>

#include "BST.cc"

using namespace std;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


void test_add_del_naive(int size) {
    vector<int> vec;
    for (int i = 0; i < size; ++i) {
        vec.push_back(i);
    }
    BST tree;

    shuffle(vec.begin(), vec.end(), default_random_engine(seed));
    cout << "Add Sequence :" << endl;
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << " "; 
    }
    cout << endl;

    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        tree.add(*iter);
        cout << "afer add element : " << *iter << endl;
        cout << tree << endl;
    }



    shuffle(vec.begin(), vec.end(), default_random_engine(seed));
    cout << "Del Sequence :" << endl;
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << " "; 
    }
    cout << endl;
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        tree.del(*iter);
        cout << "afer del element : " << *iter << endl;
        cout << tree << endl;
    }
}
void test_silent(int size) {
    cout << "In Test_silent , size = " << size << endl;

    vector<int> vec;
    for (int i = 0; i < size; ++i) {
        vec.push_back(i);
    }
    
    BST tree;

    shuffle(vec.begin(), vec.end(), default_random_engine(seed));
    set<int> cmp_set;
    int cnt = 0;

    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        tree.add(*iter);
        cmp_set.insert(*iter);
       
        auto tree_iter = tree.begin();
        // tree.putResult();

        // printf("Tree.size() = %d , Set.size() = %lu\n", tree.size(), cmp_set.size());    
        assert(tree.size() == cmp_set.size());
        
        auto set_iter = cmp_set.begin();
        for (int i = 0; i< tree.size(); ++i) {
            assert(tree.select(i) == *set_iter);                // test select 
            assert(tree.rank(tree.select(i)) == i);             // test rank
            assert(*tree_iter++ == *set_iter);
            ++set_iter;
        }
        ++cnt;
        if (cnt * 10 % size == 0) {
            printf("After %d insertion, height : %d\n", cnt, tree.height());  
        }
    }
    // iterator usage!
    /*
    for (auto tree_iter = tree.begin(); tree_iter != tree.end(); ++tree_iter) {
        cout << *tree_iter << " ";
    }
    */

    cout << endl;

    cnt = 0;
    // tree.putResult();
    shuffle(vec.begin(), vec.end(), default_random_engine(seed));
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        // cout << *iter << endl;

        tree.del(*iter);
        cmp_set.erase(*iter);
       
        auto tree_iter = tree.begin();
        // tree.putResult();

        // printf("Tree.size() = %d , Set.size() = %lu\n", tree.size(), cmp_set.size());    
        assert(tree.size() == cmp_set.size());
        
        auto set_iter = cmp_set.begin();
        for (int i = 0; i< tree.size(); ++i) {
            assert(tree.select(i) == *set_iter);                // test select 
            assert(tree.rank(tree.select(i)) == i);             // test rank
            assert(*tree_iter++ == *set_iter);
            ++set_iter;
        }
        ++cnt;
        if (cnt * 10 % size == 0) {
            printf("After %d deletion, height : %d\n", cnt, tree.height());  
        }
    }
    
    cout << "test end" << endl;
}

int main(int argc, char * argv[]) {
    srand(time(NULL));
    if (argc == 2 && strcmp(argv[1], "naive") == 0) { 
        test_add_del_naive(10);
    }else if (argc == 3 && strcmp(argv[1], "silent") == 0)  {
        test_silent(atoi(argv[2]));
    }else {
        cout << "Read Makefile first" << endl;
    }
    return 0;
}
