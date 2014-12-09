lude<stack>
#include<iostream>
using namespace std;
int  judge(int n,int *input)
{
    stack<int> a;
    int i;
    int j=0;
    for(i=1; i<=n; i++)
    {
        a.push(i);
        while(!a.empty()&&a.top()==input[j])
        {
            j++;
            a.pop();
            if(j==n)
            {
                cout<<"Yes"<<endl;
                return 1;
            }
        }
    }
    cout<<"No"<<endl;
}
int a[1111];
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        while(true)
        {
            cin >> a[0];
            if (a[0] == 0)
            {
                break;
            }
            for(int i=1; i<n; i++)
                cin >> a[i];
            judge(n, a);


        }
        cout<<'\n';
    }
    return 0;
}

