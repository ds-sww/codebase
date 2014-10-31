#include<iostream>
#include<string>
using namespace std;

int main(){
    string pattern, text;
    while(cin>>text>>pattern){
        int x = 0;
        int i,j;
        for(i=0;i<text.size();i++){
            for(j=0;j<pattern.size();j++)
                if(pattern[j]!=text[i+j])break;
            if(j==pattern.size()){
                cout<<i<<" ";
                x = 1;
            }
        }
        if(x == 0)cout<<"-1";
        cout<<endl;
    }

    return 0;
}

