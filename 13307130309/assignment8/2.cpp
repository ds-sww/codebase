#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,k;
char a[1000],b[1000];
void dfs(int l,int r)
{
    if(l>r)
        return;
    k++;
    //printf("%d %d %c\n",l,r,a[k]);
    if(l==r)
    {
        printf("%c",a[k]);
        return;
    }
    int i;
    for(i=l;i<=r;i++)
    if(a[k]==b[i])
    {
        dfs(l,i-1);
        dfs(i+1,r);
        break;
    }
    printf("%c",b[i]);
}
int main()
{
    int i,j;
    while(scanf("%s%s",a,b)!=-1)
    {
        n=strlen(a);
        k=-1;
        dfs(0,n-1);
        printf("\n");
    }
    return 0;
}
