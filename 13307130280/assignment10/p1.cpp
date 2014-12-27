#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char s[100010];
char w[1010][110];
int v[300];
int a[1010],b[1010],c[1010];
int nw[1010];
int num,numn,numw;
int len[1010];
bool cmp(char s1[],char s2[],int l1,int l2)
{
    int l = l1;
    if (l1 > l2) l = l2;
    for (int i = 0; i < l; i++)
    {
       int  tp1 = s1[i];
        int tp2 = s2[i];
        if (tp1 >= 'a' && tp1 <='z') tp1 = tp1 +'A' -'a';
        if (tp2 >= 'a' && tp2 <='z') tp2 = tp2 +'A' -'a';
        if (tp1 > tp2) return true;
        if (tp1 < tp2) return false;
    }
    if (l1 > l2) return true;
    return false;
}
int main()
{
    for (int i = 'a'; i <= 'z'; i++)
        v[i] = true;
    for (int i = 'A'; i <= 'Z'; i++)
        v[i] = true;
    while (scanf("%[^\n]\n",s) != -1)
    {
        if (s[0] =='.') break;
        memset(w,0,sizeof(w));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(len,0,sizeof(len));
        memset(nw,0,sizeof(nw));
        num = 0;
        numn = 0;
        numw = 0;
        int l = strlen(s);
        bool minu = false;
        bool word = false;
        for (int i = 0; i < l; i++)
        {
            if (s[i] == ' ') continue;
            if (s[i] == ',' || s[i] == '.')
            {
                w[num][len[num]] = '\0';
                if (!word)
                {
                    numn ++;
                    nw[num] = 1;
                    a[numn] = num;
                    int tmp = 0;
                    for (int j = 0; j < len[num]; j++)
                    if (w[num][j] != '-')
                    {
                        tmp = tmp * 10 + w[num][j] - '0';
                    }
                    if (minu) tmp = - tmp;
                    c[num] = tmp;
                }
                else
                {
                    numw ++;
                    nw[num] = 2;
                    b[numw] = num;
                }
                word = false;
                minu = false;
                num++;

                continue;
            }
            w[num][len[num]] = s[i];
            len[num]++;
            if (v[s[i]]) word = true;
            if (s[i] == '-') minu = true;
        }
        
        for (int i = 1; i < numn; i++)
        for (int j = i + 1; j <=numn; j++ )
        if (c[a[i]] > c[a[j]])
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
        for (int i = 1; i < numw; i++)
        for (int j = i + 1; j <=numw; j++ )
        if (cmp(w[b[i]],w[b[j]],len[b[i]],len[b[j]]))
        {
            int tmp = b[i];
            b[i] = b[j];
            b[j] = tmp;
        }
        int t1 = 1;
        int t2 = 1;
        for (int i = 0; i < num - 1; i++)
        if (nw[i] == 1)
        {
            printf("%s, ",w[a[t1]]);
            t1++;
        }
        else
        {
            printf("%s, ",w[b[t2]]);
            t2++;
        }
        if (nw[num - 1] == 1)
        {
            printf("%s.\n",w[a[t1]]);
        }
        else printf("%s.\n",w[b[t2]]);
    }
    return 0;
}

