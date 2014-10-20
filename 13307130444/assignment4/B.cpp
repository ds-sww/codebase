#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int N;

int work()
{
	int n=N,temp,max=0,a=0,j=0,k=-1;
	vector<int> v;
	while(n--){
		int temp;
		scanf("%d",&temp);
		v.push_back(temp);
	}
	for(int i=0;i<N;i++){
		for(a=j=0,k=-1;j<N;j++){
			if(v[j]>=v[i]);
			else {
				a=(a>(j-k-1))?a:(j-k-1);
				k=j;
			}
		}
			if(k==-1)a=j;
			max=(max>a*v[i])?max:a*v[i];
	}
	cout<<max<<endl;
	return max;
}

int main()
{
	while(scanf("%d", &N), N != 0) 
	{ 
		work(); 
	} 
 	return 0; 
} 




