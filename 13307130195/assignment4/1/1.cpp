#include "cmath"
#include "cstdlib"
#include "climits"
#include "vector"
#include "queue"
#include "map"
#include "set"
#include "string"
#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;

int n, a[1100], s[1100];

int main()
{

    while(cin>>n) {
        if (n == 0) break;
        while (cin>>a[1])
        {
            if (a[1] == 0) {
                cout<<endl;
                break;
            }
            for (int i = 2; i <= n; i++) cin>>a[i];

            if (n <= 2)
            {
                cout<<"Yes"<<endl;
                continue;
            }
            bool f = 1;
            int m = 0, t = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] > m)
                {
                    while (m != a[i]) s[++t] = ++m;
                }
                else if (a[i] != s[t])    
                {
                    f = 0;
                    break;
                }
                
                t--;
                
            }

            if (f) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }


    return 0;
}