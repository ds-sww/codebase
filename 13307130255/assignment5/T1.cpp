#include <iostream>

using namespace std;

void findpattern(string text,string pattern)
{
    int p = text.find(pattern);
    if(p==-1) { cout<<p<<endl; return;}
    while(p!=-1)
    {
        cout<<p<<" ";
        p = text.find(pattern,p+1);
    }

    cout<<endl;

}
int main()
{
    string text,pattern;
    while(1)
    {
        getline(cin,text);
        if(text.length() == 0) break;
        getline(cin,pattern);
        findpattern(text,pattern);
    }
}
