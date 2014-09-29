/**
 * Author   : Ryannnnnnn
 * Date     : Sep 30, 2014
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


class MergeFruit {
private:
    int popMinimumItem(queue <int> &a, queue <int> &b) {
        int item;
        if (b.empty() || (!a.empty() && a.front() <= b.front())) {
            item = a.front(); a.pop();
        } else {
            item = b.front(); b.pop();
        }
        return item;
    }

public:
    int minCost(vector <int> weights) {
        sort(weights.begin(), weights.end());

        queue <int> unmeged;
        queue <int> merged;
        for (vector <int>::iterator it = weights.begin(); it != weights.end(); it++)
           unmeged.push(*it);
        int cost = 0;

        while (unmeged.size() + merged.size() > 1) {
            int item1 = popMinimumItem(unmeged, merged);
            int item2 = popMinimumItem(unmeged, merged);
            merged.push(item1 + item2);
            cost += item1 + item2;
        }

        return cost;
    }
};

const int MAXN = 10000;

int main() {
    int n, weight;
    vector <int> weights;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight);
        weights.push_back(weight);
    }

    MergeFruit *mf = new MergeFruit();
    printf("%d\n", mf->minCost(weights));

    return 0;
}
