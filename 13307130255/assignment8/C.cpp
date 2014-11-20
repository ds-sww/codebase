#include <stdio.h>

int preorder[200];
int num;
void preord(int n,int m)
{
    preorder[num++] = n;
    if(n*2<=m)
        preord(n*2,m);
    if(n*2+1<=m)
        preord(n*2+1,m);
}
int main()
{
    num = 0;
    int n,i;
    scanf("%d",&n);
    while(n)
    {
        num = 0;
        preord(1,n);
        for(i=0;i<n;i++) printf("%d ",preorder[i]);
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
