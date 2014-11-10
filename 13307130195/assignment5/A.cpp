#include<cstdio>
#include<iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int lps[1000000], n, m, cnt;
string s, t;


int main()
{
    // freopen("a.in", "r", stdin);
    while (cin >> t){
        cin>>s;
        n = s.length();
        m = t.length();

        int k = -1;
        memset(lps, 0, sizeof(lps));
        lps[0] = -1;

        for (int i = 1; i < n; i++)
        {
            while (k >= 0 && s[k+1] != s[i]) k = lps[k];
            if (s[k+1] == s[i]) k++;
            lps[i] = k;
        }

        cnt = 0;
        k = -1;
        for (int i = 0; i < m; i++)
        {
            while (k >= 0 && s[k+1] != t[i]) k = lps[k];
            if (s[k+1] == t[i]) k++;
            if (k == n-1)
            {
                cout<<i - n + 1<<" ";
                ++cnt;
            }
        }
        if (cnt == 0) cout << -1 << endl;
        else cout<<endl;
    }
}