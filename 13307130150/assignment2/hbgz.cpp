#include <iostream>  
#include <cstdio>  
#include <queue>  
using namespace std;  
struct cmp  
{  
    bool operator()(const int &a, const int &b)  
  
    {  
        return a>b;  
    }  
};  
typedef priority_queue< int, vector<int>, cmp > qu;  
int main()  
{  
    qu q;  
    int n,x,y,ans=0;  
    cin >> n;  
    for (int i = 0; i < n; i++)  
    {  
        cin >> x;  
        q.push(x);  
    }  
  
    for (int i = 0; i < n-1; i++)  
    {  
        x = q.top();  
        q.pop();  
        y = q.top();  
        q.pop();  
        q.push(x+y);  
        ans = ans + x + y;  
    }  
  
    cout << ans << endl;  
}  