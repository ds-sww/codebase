#include <iostream>
#include<algorithm>

using namespace std;

bool com(int i, int j){
    return (i>j);
}

int main()
{
    int s_num;
    cin>>s_num;
    int stp_num,frd_num;
    for (int i=0; i<s_num; i++){
        cin>>stp_num>>frd_num;
    int *frd_stp=new int[frd_num];
    for (int j=0;j<frd_num;j++)
        cin>>frd_stp[j];
    sort(frd_stp,frd_stp+frd_num,com);
    int frd_needed=0,borrowed_stp=0;
    while(borrowed_stp<stp_num&&frd_needed<=frd_num){
            borrowed_stp+=frd_stp[frd_needed];
            frd_needed++;
        }
    cout <<"Scenario #"<<i+1<<":"<<endl;
    if (frd_needed<=frd_num)    cout<<frd_needed<<endl;
    else if(frd_needed>frd_num) cout<<"impossible"<<endl;
    cout<<endl;
    }
    return 0;
}
