#include <iostream>
#include <string>

using namespace std;

int c[21][21];
string s1,s2;
int m;
void calculate()
{
    c[0][0] = 0;
    c[1][0] = 1; c[1][1] = 1;
    for(int i = 2;i<=20;i++)
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i) c[i][j]  = 1;
            else c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
}
int tree(string s1,string s2)
{
    int sum = 1,num = 0;
    if(s1.compare(s2) == 0) return 1;
    int l1,l2,r1=0,r2=0;
    l1 = 1; l2 = 0;
    string n1,n2;
    while(r1<s1.length()-1)
    {
        r2 = s2.find(s1[l1]);
        n1 = s1.substr(l1,r2-l2+1);
        n2 = s2.substr(l2,r2-l2+1);
        r1 = r1 + r2 - l2 +1;
        sum = sum * tree(n1,n2);
        num++;
        l1 = l1 + r2 - l2 +1;
        l2 = r2 + 1;

    }
    return sum * c[m][num];

}
void work()
{
    int ans = tree(s1,s2);
    cout<<ans<<endl;
}

int main()
{
    calculate();
    while(cin>>m)
    {
        if(m==0) break; js = 0;
        cin>>s1>>s2;
        work();
    }
    return 0;
}


