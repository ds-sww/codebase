#include <iostream>
#include <cstdio>
#define N 20100
#define radix 4
using namespace std;
long long poww(int i,int j){
	long long k=1;
	if(j==0) return 1;
	for(int l=0;l<j;l++)
		k*=i;
	return k;
}
long long geti(long long t,int i){
	long long temp=t;
	temp=temp/poww(radix,i);
	temp=temp*poww(radix,i);
	t=t-temp;
	t=t/poww(radix,i-1);
	return t;
}
int main(){
	int m,n,count;
	int c[N],r[radix];
	long long a[N],b[N];
	long long tem;
	char temp;
	while(1){
		cin>>n>>m;
		if(!m&&!n)
			break;
		for(int i=0;i<N;i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
		}
		for(int i=0;i<n;i++)
			for(int j=m-1;j>=0;){
				scanf("%c",&temp);
				if(temp==' '||temp=='\n')
					continue;
				switch(temp){
					case 'A':break;
					case 'C':a[i]+=poww(radix,j);break;
					case 'G':a[i]+=2*poww(radix,j);break;
					case 'T':a[i]+=3*poww(radix,j);break;
					default:break;
				}
				j--;
			}
		for(int i=1;i<=m;i++){
			for(int j=0;j<radix;j++)
				r[j]=0;
			for(int j=0;j<n;j++)
				r[geti(a[j],i)]++;
			for(int j=1;j<radix;j++)
				r[j]+=r[j-1];
			for(int j=n-1;j>=0;j--)
				b[--r[geti(a[j],i)]]=a[j];
			for(int j=0;j<n;j++)
				a[j]=b[j];
		}
		tem=a[0];count=0;
		for(int i=0;i<n;i++)
			if(a[i]==tem)
				count++;
			else{
				tem=a[i];
				c[count-1]++;
				count=1;
			}
		c[count-1]++;
		for(int i=0;i<n;i++)
			cout<<c[i]<<endl;
	}
}