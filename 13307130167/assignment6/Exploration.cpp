#include <iostream>
#include  <math.h>

using namespace std;

int main()
{
    int lan=0;
    int lmks[50010];
    int T=0,N=0;
    cin>> T >> N;
    lmks[0]=0;
    for (int i=1 ; i<N+1 ; i++)
        cin >> lmks[i];
        int j=0;
    for (int i=1; i < N ; i++)
        for ( j= i-1,lan=lmks[i]; j>=0 && fabs(lan)< fabs(lmks[j]) ; j--)
            lmks[j+1]=lmks[j];
        lmks[j+1]=lan;

        int used_T=0;
        int lmk_cnt= -1;
        for (int i=0 ; i< N-1&&used_T<=T ;i++){
            used_T+=fabs(lmks[i+1]-lmks[i]);
            lmk_cnt++;
        }
        cout << lmk_cnt ;
        return 0;
    }
