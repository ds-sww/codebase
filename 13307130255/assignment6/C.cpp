#include <stdio.h>

using namespace std;

int a1[100000];
int a2[100000];
void qsort(int a[],int l,int r)
{
    int x=a[l],i=l,j=r;
    while(i<j)
    {
        while(i<j&&a[j]>=x) j--;
        if(i<j) a[i] = a[j];
        while(i<j&&a[i]<=x) i++;
        if(i<j) a[j] = a[i];
    }
    a[i] = x;
    if(i-1>l) qsort(a,l,i-1);
    if(i+1<r) qsort(a,i+1,r);
}

int main()
{
    int n,m,i,j,ans;
    scanf("%d %d",&n,&m);
    while(n!=0||m!=0)
    {
        ans = 0;
        for(i=0;i<n;i++) scanf("%d",&a1[i]);
        for(i=0;i<m;i++) scanf("%d",&a2[i]);
        qsort(a1,0,n-1);
        qsort(a2,0,m-1);
        i = j = 0;
        while(i<n&&j<m)
        {
            if(a1[i]<=a2[j])
            {
                ans +=a2[j];
                i++; j++;
            }else j++;
        }
        if(i==n) printf("%d\n",ans);
        else printf("Loowater is doomed!\n");
        scanf("%d %d",&n,&m);
    }
    return 0;
}

