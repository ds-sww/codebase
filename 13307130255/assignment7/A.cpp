#include <stdio.h>
#include <algorithm>

using namespace std;
int a[100000];
int main()
{
    int t,i,j,sum,m,n,tt=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        sum=0;
        for(i=n-1;i>=0;i--)
        {
            sum+=a[i];
            if(sum>=m)
            {
                printf("Scenario #%d:\n%d\n\n",tt++,n-i);
                break;
            }
        }
        if(sum<m) printf("Scenario #%d:\nimpossible\n\n",tt++);
    }
    return 0;
}
