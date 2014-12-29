#include<iostream>
#include<cstdio>
#include<set>
#include<string>

using namespace std;

int main(void){
    int t, n ,m;
    cin>>t;
    for(int cnt = 1;cnt <= t; cnt++){
        set<long long> mat;
        cin>>n>>m;
        string *l = new string[n];
        long long li[m], c;
        int i,j,k,p,q;
        for(i=0;i<n;i++)
            cin>>l[i];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                for(p=j;p<m;p++)
                    li[p]=0;
                for(k=i;k<n;k++){
                    c = 0;
                    for(q=j;q<m;q++){
                        li[q]=(li[q]<<2)+l[k][q];
                        c = (c<<4)+li[q]*li[q];
                        mat.insert(c);
                    }
                }
            }
        }
        cout<<"Case #"<<cnt<<": "<<mat.size()<<endl;
    }
    return 0;
}