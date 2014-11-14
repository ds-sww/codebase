
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct cmp
{
    bool operator ()(const int& a,const int& b)
    {
        return a>b;
    }
};

priority_queue<int> max_q;
priority_queue<int> max_rq;
priority_queue<int,vector<int>,cmp> min_q;
priority_queue<int,vector<int>,cmp> min_rq;
int a[1000100],nmin[1000100],nmax[1000100];
int n,k;
int main(int argc, char **argv)
{
	scanf("%d %d",&n,&k);
    int i;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<k;i++)
    {
        max_q.push(a[i]);
        min_q.push(a[i]);
    }
    nmin[0] = min_q.top();
    nmax[0] = max_q.top();
    for(i=k;i<n;i++)
    {
        min_rq.push(a[i-k]);
        max_rq.push(a[i-k]);
        min_q.push(a[i]);
        max_q.push(a[i]);
        while(!min_rq.empty() && min_q.top()==min_rq.top())
        {
            min_q.pop(); min_rq.pop();
        }
        while(!max_rq.empty() && max_q.top()==max_rq.top())
        {
            max_q.pop(); max_rq.pop();
        }
        nmin[i-k+1] = min_q.top();
        nmax[i-k+1] = max_q.top();
    }
    for(i=k-1;i<n;i++) printf("%d ",nmin[i-k+1]);
    printf("\n");
    for(i=k-1;i<n;i++) printf("%d ",nmax[i-k+1]);
	return 0;
}

