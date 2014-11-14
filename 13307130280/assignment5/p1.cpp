//BF.
//本来用KMP，但输入出了问题，担心debug花的时间长，放弃了KMP。
//

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=10001;
char s1[MAXN],s2[MAXN];
int ans[MAXN];
int i,j,l1,l2,num;
int main()
{
    while (scanf("%s",s1)!=-1)
    {
        scanf("%s",s2);
        num=0;
        j=0;
        while (s2[j]!='\0') j++;
        l2=j;
        i=0;
        while (s1[i]!='\0') i++;
        l1=i;
        for (int i=0;i<l1;i++)
        {
            j=0;
            while (j<l2 && s1[i+j]==s2[j])
            {
                j++;
            }
            if (j==l2)
            {
                num++;
                ans[num]=i;
            }

        }
        for (int i=1;i<num;i++)
            printf("%d ",ans[i]);
        if (num>0)printf("%d\n",ans[num]);
        else printf("-1\n");
    }
    return 0;
}
