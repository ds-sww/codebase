#include <iostream>
#include <vector>

using namespace std;

template <class Item>
void transfer (vector< Item>& v,vector< Item>& a)
{
    if(!a.empty())
        v.push_back(a.back());
        a.pop_back();
}

template <class Item>
void merge ( vector< Item>& v, int left, int m,int right )
{
    int i,j;
    vector<Item> a,b;
    for (i=right;i>m;i--)
        a.push_back(v[i]);
    for( j=m;j>=left;j--)
        b.push_back(v[j]);
    for( int k=left;k<=right;k++)
    {
        if(!a.empty()&&!b.empty())
            if(a.back()<b.back()) { v[k]=a.back();a.pop_back();}
            else { v[k]=b.back();b.pop_back();}
        else if(!a.empty()&&b.empty()){ v[k]=a.back();a.pop_back();}
        else if(a.empty()&&!b.empty()){ v[k]=b.back();b.pop_back();}
    }
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
}


template<class Item>
void mergesort(vector< Item>&v,int left, int right)
{
    if(right <=left)return;
    int m=(right+left)/2;
    mergesort(v,left,m);
    mergesort(v,m+1,right);
    merge(v,left,m,right);
}



int main()
{
    vector<int>a;
    int c,m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>c;
        a.push_back(c);
    }
    mergesort(a,0,a.size()-1);
  for(int i=0;i<m;i++)
    cout<<a[i]<<" ";
    return 0;
}
