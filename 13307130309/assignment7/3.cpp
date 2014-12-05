#include<stdio.h>
#include<stdlib.h>
int n;
int a[100001];
int s[100001],pos[100001],p;
long long ans;
int main()
{
    int i,j,w,wer;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    ans=0;
    for(i=n-1;i>=0;i--)
    {
        while(p>0&&a[i]>s[p-1])
            p--;
        if(p!=0)
            ans+=pos[p-1]-1-i;
        else
            ans+=n-1-i;
        s[p]=a[i];
        pos[p]=i;
        p++;
    }
    printf("%lld\n",ans);
    return 0;
}
