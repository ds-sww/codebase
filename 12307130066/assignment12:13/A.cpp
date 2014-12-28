#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
struct edge {
        int target;
        int Distance;
};

edge links[10000][10000];
int link_count[10000];
int Distance[10000];
int prevs[10000][10000][3];
int prev_count[10000];
int SUM = 0;

void findWay(int index) {
        if(index == 0)
                return;
        for(int i = 0; i < prev_count[index]; i++) {
                if(prevs[index][i][2] == 0) {
                        prevs[index][i][2] = 1;
                        SUM += prevs[index][i][1];
                        findWay(prevs[index][i][0]);
                }
        }
}

int main() {
        int P, T;
        scanf("%d%d", &P, &T);
        for(int i = 0; i < P; i++) {
                link_count[i] = 0;
                prev_count[i] = 0;
                Distance[i] = 10000000;
        }
        Distance[0] = 0;
        int tmp1, tmp2, tmp3;
        for(int i = 0; i < T; i++) {
                scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
                if(tmp1 == tmp2)
                	continue;
                links[tmp1][ link_count[tmp1]++ ].target = tmp2;
                links[tmp1][ link_count[tmp1]-1 ].Distance = tmp3;
                links[tmp2][ link_count[tmp2]++ ].target = tmp1;
                links[tmp2][ link_count[tmp2]-1 ].Distance = tmp3;
        }
        vector<int> queue;
        vector<int> queue_currDistance;
        queue.push_back(0);
        queue_currDistance.push_back(0);
        int curr = 0, tmp, tmpDistance;
        while(curr < queue.size()) {
                tmp = queue[curr++];
                tmpDistance = queue_currDistance[curr-1];
                for(int i = 0; i < link_count[tmp]; i++) {
                        if(tmpDistance + links[tmp][i].Distance < Distance[ links[tmp][i].target ]) {
                                Distance[ links[tmp][i].target ] = tmpDistance + links[tmp][i].Distance;
                                prev_count[ links[tmp][i].target ] = 0;
                                prevs[ links[tmp][i].target ][ prev_count[ links[tmp][i].target ]++ ][0] = tmp;
                                prevs[ links[tmp][i].target ][ prev_count[ links[tmp][i].target ]-1 ][1] = links[tmp][i].Distance;
                                prevs[ links[tmp][i].target ][ prev_count[ links[tmp][i].target ]-1 ][2] = 0;
                                queue.push_back(links[tmp][i].target);
                                queue_currDistance.push_back(Distance[ links[tmp][i].target ]);
                        }
                        else if(Distance[tmp] + links[tmp][i].Distance == Distance[ links[tmp][i].target ]) {
                                prevs[ links[tmp][i].target ][ prev_count[ links[tmp][i].target ]++ ][0] = tmp;
                                prevs[ links[tmp][i].target ][ prev_count[ links[tmp][i].target ]-1 ][1] = links[tmp][i].Distance;
                                prevs[ links[tmp][i].target ][ prev_count[ links[tmp][i].target ]-1 ][2] = 0;
                        }
                }
        }
        findWay(P - 1);
        cout << SUM * 2 << endl;
        return 0;
}