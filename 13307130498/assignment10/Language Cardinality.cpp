#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
struct A{
    string ori,rep;
}ru[101];
int size,i,j;
string s,x;
set<string> bef;
void cal(string str){
    for(int m=0;m<size;m++){
        int jj=0;
        while(str.find(ru[m].ori,jj)!=string::npos){
            string newstr=str;
            newstr.replace(newstr.find(ru[m].ori,jj),ru[m].ori.size(),ru[m].rep);
            if(bef.count(newstr)==0){
                bef.insert(newstr);
                if(bef.size()>1000)throw "XYWBD";
                cal(newstr);
            }
            jj=str.find(ru[m].ori,jj)+1;
        }
    }
}
int main(void){
    cin>>s;
    s=s.substr(1,s.size()-2);
    i=j=0;
    while(cin>>x){
        j=x.find("->");
        ru[i].ori=x.substr(1,j-2);
        ru[i].rep=x.substr(j+3,x.size()-j-4);
        i++;
    }
    size=i;
    bef.insert(s);
    try{
        cal(s);
    }
    catch(const char *mm){
        cout<<"Too many."<<endl;
        return 0;
    }
    cout<<bef.size()<<endl;
    return 0;
}