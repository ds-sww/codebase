#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

int a[55];
int c[55];
int n;
int top;
vector<int> link[55];

void make_tree()
{
	for(int i=0;i<n;i++)
	{
		for(int j=1;;j++)
		if(c[j]==0)
		  {
		  link[a[i]].push_back(j);
		  c[j]--;
		  c[a[i]]--;
		  break;
          }
	}
	
}
void print_tree(int u)
{
	printf("(");
    printf("%d",u);
    for(vector<int>::iterator iter=link[u].begin();iter!=link[u].end();iter++)
    {
        printf(" ");  
        print_tree(*iter);
    }
    printf(")");

	
}


int main()
{
	string buf;
    while(getline(cin,buf))
    {
		for(int i=0;i<55;i++)
            link[i].clear();
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		stringstream ss(buf);
		for(n=0;ss>>a[n];n++);
		if(n==0) 
		  top=1;
		else
		  top=a[n-1];
		for(int i=0;i<n;i++)
			c[a[i]]++;
		make_tree();
		print_tree(top);
		cout << endl;
	}
	return 0;
	
	
	
	
}

