#include <iostream>
#include <cstring>
using namespace std;

int C[30][30];
char pre[30];
char pos[30];
int m;

void setC() {
    C[0][0] = 0;
    for (int i = 0; i <= 20; i++)
        C[i][0] = 1;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
}

int dfs(int curpre, int endpre, int curpos, int endpos) {
    if (curpre == endpre) return 1;
    int son = 0, ans = 1;
    int cpre = curpre+1, cpos = curpos;
    while (cpre <= endpre) {
        while (cpos < endpos) {
            if (pre[cpre] == pos[cpos]) {
                son++;
                break;
            }
            cpos++;
        }
        ans *= dfs(cpre, cpre+cpos-curpos, curpos, cpos);
        cpre = cpre + cpos - curpos + 1;
        curpre = cpre - 1;
        curpos = ++cpos;
    }
    return ans * C[m][son];
}

int main() {
    setC();
    while (cin >> m) {
        if (m == 0) return 0;
        cin >> pre >> pos;
        cout << dfs(0, strlen(pre)-1, 0, strlen(pos)-1) << endl;
    }
}
