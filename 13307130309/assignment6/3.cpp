#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m;
int a[1000001],b[1000001];
int time,tot,ans;
int check(int a)
{
    if(a>0)
        return a;
    return -a;
}
void qs(int *a,int l,int r)
{
    int i,j,step=a[(l+r)/2];
    i=l,j=r;
    while(i<=j)
    {
        while(i<=j&&a[i]<step) i++;
        while(i<=j&&step<a[j]) j--;
        if(i<=j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++,j--;
        }
    }
    if(l<j)
        qs(a,l,j);
    if(i<r)
        qs(a,i,r);
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    while(n!=0&&m!=0)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        qs(a,0,n-1);
        qs(b,0,m-1);
        int p=0;
        ans=0;
        for(i=0;i<m;i++)
        if(a[p]<=b[i])
        {
            p++;
            ans+=b[i];
            if(p==n)
                break;
        }
        if(p==n)
            printf("%d\n",ans);
        else
            printf("Loowater is doomed!\n");
        scanf("%d%d",&n,&m);
    }
    return 0;
}
