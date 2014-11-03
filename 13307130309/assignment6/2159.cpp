#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

string a,b;
int hash_a[27],hash_b[27];
int main()
{
	int i,j,m;
	while(cin>>a)
	{
		cin>>b;
		m=a.length();
		for(j=0;j<=26;j++)
			hash_a[j]=hash_b[j]=0;
		for(j=0;j<m;j++)
			hash_a[a[j]-'A']++;
		for(j=0;j<m;j++)
			hash_b[b[j]-'A']++;
		for(i=0;i<26;i++)
			for(j=i+1;j<26;j++)
			if(hash_a[i]<hash_a[j])
			{
				int k=hash_a[i];
				hash_a[i]=hash_a[j];
				hash_a[j]=k;
			}
		for(i=0;i<26;i++)
			for(j=i+1;j<26;j++)
			if(hash_b[i]<hash_b[j])
			{
				int k=hash_b[i];
				hash_b[i]=hash_b[j];
				hash_b[j]=k;
			}

		for(i=0;i<26;i++)
		{
			for(j=0;j<26;j++) 
			if(hash_a[(j+i)%26]!=hash_b[j])
				break;
			if(j==26)
				break;
		}
		if(i==26)
			cout<<"NO\n";
		else
			cout<<"YES\n"; 
	}
	return 0;
}
