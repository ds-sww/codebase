#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<deque>  
using namespace std;  
int main()  
{  
    int n;  
    cin >> n; 
    deque<int>q;
    int ans=0;  
    for(int i=0;i<n;i++)  
    {  
        int w;  
        cin >> w;
        while(!q.empty()&&q.back()<=w)  
        {  
            q.pop_back();  
        }  
        ans+=q.size();  
        q.push_back(w);  
    }  
    printf("%u\n",ans);  
    return 0;  
}  
