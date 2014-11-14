#include <iostream>
using namespace std;
int main()
{
	int n,a[1100],b[1100];
	cin >> n;
	while (n!=0)
	{
		int flag=1;
		cin >> a[0];
		if (a[0] != 0)
			for (int i=1; i<n; i++)
				cin >> a[i];
		else {cin >> n; if (n!=0) cout << endl; continue;}

		int top=0,top2=0;
		for (int i=1; i<=n; i++)
		{
			top2++; b[top2]=i;
			while (top2>0&&b[top2]==a[top])
			{top2--; top++;}
		}
		if (top2!=0) flag=0;

		if (flag==1)
			cout << "Yes" <<endl;
		else cout << "No" <<endl;
	}
}