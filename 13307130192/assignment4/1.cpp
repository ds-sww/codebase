#include<iostream>
#include<stack>
#include<cstdio>
#define For(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
const int mN=2000;

int a[mN];
stack<int> st;
int main()
{
    //freopen("1.in","r",stdin);
    int n;
    while(cin>>n)
    {
        if (n==0)
            break;
        while(1)
        {
            int x;
            cin>>x;
            if (x==0)
                break;
            a[1]=x;
            For(i,2,n)
                cin>>a[i];
            while (!st.empty())
                st.pop();
            int now=1;
            bool can=true;
            For(i,1,n)
            {
                while (now<=a[i])
                {
                    st.push(now);
                    now++;
                }
                if (st.top()==a[i])
                    st.pop();
                else
                {
                    can=false;
                    break;
                }
            }
            cout<<(can?"Yes":"No")<<endl;
        }
        cout<<endl;
//        cout<<"me"<<endl;
    }
}
