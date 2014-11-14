#include<iostream>
using namespace std;
 
int main()
{
    int a[1005],b[1005],i,j,k,n;
    while(cin>>n,n)
    {
        while(cin>>b[0],b[0])
        {
            for(j=1; j<n; j++)
                cin>>b[j];
            for(i=1,j=0,k=0; i<=n&&j<n; i++,k++)
            {
                a[k]=i;
                while(a[k]==b[j])
                {
                    if(k>0)k--;
                    else
                    {
                        a[k]=0,k--;
                    }
                    j++;
                    if(k==-1)break;
                }
            }
            if(j==n)
				cout<<"Yes"<<endl;
            else 
				cout<<"No"<<endl;
        }
        cout<<endl;
    }
}
