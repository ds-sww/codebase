#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f(char c)
{
    switch (c)
    {
        case '+':return 1;
        case '-':return 2;
        case '*':return 3;
        case '/':return 4;
        case '^':return 5;
        case ')':return 6;
        case '(':return 0;
        default: return -1;
    }
}
int main()
{
    char s[1000];
    int i,j,top1,top2,a[1000],b[1000],c1[10],c2[10],temp,t,x;
    while(cin>>s)
    {
        for (i=0;i<1000;i++)
       {
            a[i]=-1;b[i]=0;
        }
        c1[0]=c2[0]=0;
        c1[1]=c1[2]=c2[1]=c2[2]=1;
        c1[3]=c1[4]=c2[3]=c2[4]=2;
        c1[5]=3;c2[5]=4;
        i=0;top1=0;top2=0;temp=2147483647;
        while (s[i])
        {
            t=f(s[i]);
            switch (t)
            {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    if (temp<2147483647)
                    {
                        top2++;
                        b[top2]=temp;
                        temp=2147483647;
                    }
                    if ((top2==0)||(s[i-1]=='(')) top2++;
                    while (c2[t]<=c1[a[top1]])
                    {
                        switch (a[top1])
                        {
                            case 1: top2--;b[top2]=b[top2]+b[top2+1];b[top2+1]=0; break;
                            case 2: top2--;b[top2]=b[top2]-b[top2+1];b[top2+1]=0; break;
                            case 3: top2--;b[top2]=b[top2]*b[top2+1];b[top2+1]=0; break;
                            case 4: top2--;b[top2]=b[top2]/b[top2+1];b[top2+1]=0; break;
                            case 5: top2--;x=b[top2];b[top2]=1;
                                    for (j=0;j<b[top2+1];j++) b[top2]=b[top2]*x;
                                    b[top2+1]=0; break;
                            default: break;
                        }
                        top1--;
                    }
                    top1++;
                    a[top1]=t;
                    break;
                case 0: top1++;a[top1]=t; break;
                case 6:
                    if (temp<2147483647)
                    {
                        top2++;
                        b[top2]=temp;
                        temp=2147483647;
                    }
                    while (a[top1])
                    {
                        switch (a[top1])
                        {
                            case 1: top2--;b[top2]=b[top2]+b[top2+1];b[top2+1]=0; break;
                            case 2: top2--;b[top2]=b[top2]-b[top2+1];b[top2+1]=0; break;
                            case 3: top2--;b[top2]=b[top2]*b[top2+1];b[top2+1]=0; break;
                            case 4: top2--;b[top2]=b[top2]/b[top2+1];b[top2+1]=0; break;
                            case 5: top2--;x=b[top2];b[top2]=1;
                                    for (j=0;j<b[top2+1];j++) b[top2]=b[top2]*x;
                                    b[top2+1]=0; break;
                            default: break;
                        }
                        top1--;
                    }
                    top1--;
                    break;
                default:
                    if (temp==2147483647) temp=s[i]-48;
                    else temp=temp*10+s[i]-48;
                    break;
            }
            i++;
        }
        if (temp<2147483647)
        {
            top2++;
            b[top2]=temp;
            temp=2147483647;
        }
        while (a[top1]!=-1)
        {
            switch (a[top1])
            {
                case 1: top2--;b[top2]=b[top2]+b[top2+1];b[top2+1]=0; break;
                case 2: top2--;b[top2]=b[top2]-b[top2+1];b[top2+1]=0; break;
                case 3: top2--;b[top2]=b[top2]*b[top2+1];b[top2+1]=0; break;
                case 4: top2--;b[top2]=b[top2]/b[top2+1];b[top2+1]=0; break;
                case 5: top2--;x=b[top2];b[top2]=1;
                for (j=0;j<b[top2+1];j++) b[top2]=b[top2]*x;
                b[top2+1]=0; break;
                default: break;
            }
            top1--;
        }
        cout<<b[1]<<endl;
    }
    return 0;
}
