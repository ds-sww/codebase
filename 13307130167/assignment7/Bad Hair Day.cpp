#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

class Cow{
public:
    Cow()   {   height=0;   can_see_cnt=0;  }
    int height;
    int can_see_cnt;
};

bool operator <(const Cow a,const Cow b){
    return (a.height<b.height);
}

int main()
{
    int n;
    cin>>n;
    Cow *cows=new Cow[n];
    for (int i =0;i<n;i++)
        scanf("%d",&cows[i].height);
    long long total=0;
    stack<Cow> s;
    s.push(cows[n-1]);
    for (int i=n-2;i>=0;i--){
        if(cows[i]<s.top()){
            s.push(cows[i]);
            continue;
        }
        while(!s.empty()&&s.top()<cows[i]){
            cows[i].can_see_cnt=cows[i].can_see_cnt+s.top().can_see_cnt+1;
            s.pop();
        }
        s.push(cows[i]);
        total+=cows[i].can_see_cnt;
    }
   cout<<total;
   delete cows;
    return 0;
}
