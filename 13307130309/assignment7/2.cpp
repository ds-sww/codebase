#include<stdio.h>
#include<stdlib.h>
int contain;
int n,len;
char g[100001][40];
long long b[100001],a[100001];
int hash[100001];
void merge(long long *a,int l,int r)
{
    if(l>=r)
        return;
    int mid=(l+r)/2;
    merge(a,l,mid);
    merge(a,mid+1,r);
    int i=l,j=mid+1,m=0;

    for(;i<=mid;i++,m++)
    {
        for(;j<=r&&a[i]>a[j];j++,m++)
            b[m]=a[j];
        b[m]=a[i];
    }
    for(;j<=r;j++,m++)
        b[m]=a[j];
    for(i=l;i<=r;i++)
        a[i]=b[i-l];
}
int main()
{
    int i,j,w,wer;
    scanf("%d%d",&n,&len);
    while(n!=0&&len!=0)
    {
        for(i=0;i<n;i++)
            scanf("%s",g[i]);
        for(i=0;i<n;i++)
        {

            a[i]=0;
            for(j=0;j<len;j++)
            {
                a[i]*=4;
                if(g[i][j]=='A')
                {
                    a[i]+=3;
                }
                if(g[i][j]=='C') a[i]+=2;
                if(g[i][j]=='G') a[i]+=1;
            }
        }
        merge(a,0,n-1);
        int cnt=1;
        for(i=0;i<=n;i++)
            hash[i]=0;
        for(i=1;i<n;i++)
        if(a[i]!=a[i-1])
        {
            hash[cnt]++;
            cnt=1;
        }
        else
            cnt++;

        hash[cnt]++;
        for(i=1;i<=n;i++)
            printf("%d\n",hash[i]);
        scanf("%d%d",&n,&len);
    }
    return 0;
}
