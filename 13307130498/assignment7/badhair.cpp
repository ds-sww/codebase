#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

typedef pair<long long, long> pairs;

int main(){
    long N,i,sum=0,now;
    cin>>N;
    long long h[N];
    for(i=0;i<N;i++)
        cin>>h[i];
    stack<pairs> pa;
    for(i=0;i<N;i++){
        if(!pa.empty()){
            if(pa.top().first>h[i]){
                pa.top().second++;
                pa.push(pairs(h[i],0));
            }
            else{
                now=pa.top().second;
                sum+=now;
                pa.pop();
                if(!pa.empty())
                    pa.top().second+=now;
                i--;
            }
        }
        else {
            pa.push(pairs(h[i],0));
        }
    }
    while(!pa.empty()){
        now=pa.top().second;
        sum+=now;
        pa.pop();
        if(!pa.empty())
            pa.top().second+=now;
    }

    cout<<sum<<endl;
    return 0;
}
