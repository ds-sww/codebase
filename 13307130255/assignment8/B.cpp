#include <iostream>
#include <string>
#include <queue>

using namespace std;
string preorder,inorder;
queue<char> ans;

void tree(int l,int r,int&n)
{
    int m = inorder.find(preorder[n]);
    if(l<m) tree(l,m-1,++n);
    if(m<r) tree(m+1,r,++n);
    ans.push(inorder[m]);

}
void work()
{
    int i = 0;
    tree(0,preorder.length() -1,i);
    while(!ans.empty())
    {
        cout<<ans.front();
        ans.pop();
    }
    cout<<endl;

}

int main()
{
    while(cin>>preorder>>inorder)
    {
        if(preorder.length()==0) break;
        work();

    }

}
