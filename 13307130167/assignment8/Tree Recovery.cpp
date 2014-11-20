#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string  post_ord(string preord, string inord){
    if(preord.size()<=1 )     return preord;
    int i=inord.find(preord[0],0);
    string lchild_preord=preord.substr(1,i);
    string lchild_inord=inord.substr(0,i);
    string rchild_preord=preord.substr(i+1,preord.size()-i-1);
    string rchild_inord=inord.substr(i+1,inord.size()-i-1);
    string postord=post_ord(lchild_preord,lchild_inord)+post_ord(rchild_preord,rchild_inord)+preord[0];
    return postord;
}

int main()
{
    string pre,in;
    while(cin>>pre>>in){
        cout<<post_ord(pre,in)<<endl;
    }
    return 0;
}

