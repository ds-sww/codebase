/**
 * Author   : Ryannnnnnn
 * Date     : Sep 30, 2014
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <tuple <int, int, int> > data;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        data.push_back(make_tuple(-(a + b + c), -a, i + 1)); // Trick :P
    }

    sort(data.begin(), data.end());
    for (int i = 0; i < 5; i++)
        cout << get<2>(data[i]) << " " << -get<0>(data[i]) << endl;
    return 0;
}
