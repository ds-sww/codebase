/**
 * @author whimsycwd
 * @date   2014.11.1
 */

#ifndef SORTABLE_H
#define SORTABLE_H 1

#include<vector>

using namespace std;

// in order to simplify test
class Sortable {
    public :
        virtual void sort(vector<int> &data)  = 0;
        virtual ~Sortable () {
        }
};

#endif

