#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,k;
void dfs(int e)
{
	k++;
    if(k==n)
    printf("%d\n",e+1);
    else
    printf("%d ",e+1);
    if(e*2+1<n)
        dfs(e*2+1);
    if(e*2+2<n)
        dfs(e*2+2);
}
int main()
{
    int i,j;
    scanf("%d",&n);
    while(n!=0)
    {
        k=0;
        dfs(0);
        scanf("%d",&n);
    }
    return 0;
}
