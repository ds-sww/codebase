#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;

vector<int> men;
int coppy[22000];
int n,m;
//char tmp[22];
string tmp;
int i,j,g,h;
int main(){
	std::ios_base::sync_with_stdio(false);
	while(1){
		cin >> n >> m;
		//scanf("%d%d",&n,&m);
		if(m==0 && n==0)
			return 0;
		men.resize(n);
		for(i=0;i<n;i++){
			coppy[i]=0;
			cin >> tmp;
			//scanf("%s",tmp);
			men[i]=0;
			for(j=0;j<m;j++){
				men[i] <<=2;
				switch(tmp[j]){
					case 'A':men[i]+=1;break;
					case 'C':men[i]+=2;break;
					case 'G':men[i]+=3;break;
					//case 'T':men[i]+=0;break;
				}
				
			}
			coppy[i]=0;
		}
		sort(men.begin(),men.end());
		i=0;j=1;
		coppy[n]=0;
		for(;j<n;j++){
			//cout << i << ' ' << j << ' ' << men[i] << ' ' << men[j] << endl;
			if(men[i]!=men[j]){
				coppy[j-i]++;
				i=j;
			}
		}
		coppy[j-i]++;
		for(i=1;i<=n;i++)
			cout << coppy[i] << endl;
			//printf("%d\n",coppy[i]);
	}

}