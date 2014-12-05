#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m;
char pre[1001],post[1001];
int pos[1001],k,c[1000][1001];
long long ans;

void dfs(int l,int r)
{
    if(l>r)
        return;
    k++;
    //if(l!=r)
     if(l==r)
        return;
    int i,last=l-1,cnt=0;
    for(i=k+1;i<n&&pos[i]<r;)
    {
        dfs(last+1,pos[i]);

        int temp=last;
        last=pos[i];
        i+=pos[i]-temp;
        cnt++;
    }
    ans*=c[m][cnt];
}
int main()
{
    int i,j;
    for(i=0;i<100;i++)
    c[0][i]=0;
    c[0][0]=1;
    for(i=1;i<100;i++)
    {
        c[i][0]=1;
        for(j=1;j<100;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    scanf("%d",&m);
    while(m!=0)
    {
        k=-1;ans=1;
        scanf("%s%s",pre,post);
        n=strlen(pre);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            if(pre[i]==post[j])
                pos[i]=j;
        dfs(0,n-1);
        printf("%lld\n",ans);


        scanf("%d",&m);
    }
    return 0;
}
