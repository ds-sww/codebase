#include <iostream>
#include <vector>
using namespace std;

/*int partition(vector <int >&a, int left,int right)
{
    int i=left,j=right-1,tmp=a[right];
    while(true)
    {
        while(a[i]<tmp)i++;
        while(j>=left&&a[j]>tmp)j--;
        if(j<left)break;
        if(j<=i)break;
        swap(a[i],a[j]);
    }
    swap(a[i],a[right]);
  return i;
}

void sort(vector<int>&a,int left, int right)
{
    int i;
    if(right<=left)return;//finish iteration
    i=partition(a,left,right);
    sort(a,left, i-1);
    sort(a,i+1,right);

}

void sort(vector<int> &a)
{
    sort(a,0,a.size()-1);
}
*/
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

void work(vector<int>a,vector<int>b)
{
    int i, m=a.size(),n=b.size(),cnt=0,sum=0;
    for(i=0;i<m&&cnt<n;)
    {
        if(a[i]<=b[cnt])
        {
            sum+=b[cnt];
            i++;
            cnt++;
        }
        else cnt++;
    }
  if(i==m)
        cout<<sum<<endl;
   else
        cout<<"Loowater is doomed!"<<endl;

}

int main()
{
    int i,j,k,d;
    vector <int>Knight, Dragon;
    while(cin>>i,cin>>j,i!=0&&j!=0)
    {
        Knight.clear();
        Dragon.clear();
        if(i>j)continue;
        for(int m=0;m<i;m++)
        {
            cin>>d;
            Dragon.push_back(d);
        }
        for(int m=0;m<j;m++)
        {
            cin>>k;
            Knight.push_back(k);
        }
        //sort(Dragon);sort(Knight);
        mergesort(Dragon,0,Dragon.size()-1);
        mergesort(Knight,0,Knight.size()-1);
        work(Dragon,Knight);
    }
}
