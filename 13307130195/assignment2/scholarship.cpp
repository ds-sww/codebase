/**
 *  @author forward
 *  @date   2014.9.29
 *
 */

#include "cstdio"
#include "iostream"
#include "algorithm"


using namespace std;

struct stu{
    int ch, ma, en, id, sum;
}s[500];

int n;

int main(int argc, char const *argv[])
{
    //freopen("1.txt", "r", stdin);

    cin>>n;

    for (int i = 1; i <= n; i++){
        cin>>s[i].ch>>s[i].ma>>s[i].en;
        s[i].id = i;
        s[i].sum = s[i].ch + s[i].ma + s[i].en;
    }


    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        if ((s[j].sum > s[i].sum) ||
            (s[j].sum == s[i].sum && s[j].ch > s[i].ch) ||
            (s[j].sum == s[i].sum && s[j].ch == s[i].ch && s[j].id < s[i].id))
        {
            swap(s[i],s[j]);
        }

    for (int i = 1; i <= 5; i++) cout<<s[i].id<<" "<<s[i].sum<<endl;

    return 0;
}