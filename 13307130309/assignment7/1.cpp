#include<stdio.h>
#include<stdlib.h>
int contain;
int n;
int b[100001],a[100001];
void merge(int *a,int l,int r)
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
    scanf("%d",&wer);
    for(w=0;w<wer;w++)
    {
        scanf("%d%d",&contain,&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        merge(a,0,n-1);
        int cnt=0;
        for(i=n-1;i>=0;i--)
        {
            cnt+=a[i];
            if(cnt>=contain)
            {
                printf("Scenario #%d:\n%d\n\n",w+1,n-1-i+1);
                break;
            }
        }
        if(i==-1)
            printf("Scenario #%d:\nimpossible\n\n",w+1);
    }
    return 0;
}
