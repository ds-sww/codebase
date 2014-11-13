#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
vector<long long> man;
int occ[40000];
char dna[30];
int n,m;
int i,j,g,h;
long long tmp;
int main(){
    while(1){
	scanf("%d%d",&n,&m);
	if(n==0 && m==0)
		return 0;
        man.clear();
	for(i=0;i<n;i++){
	    scanf("%s",dna);
	    tmp = 0;
	    for(j=0;j<m;j++){
		tmp = tmp << 2;
		switch(dna[j]){
		    case 'A':tmp+=1;break;
		    case 'C':tmp+=2;break;
		    case 'G':tmp+=3;break;
		}
	    }
	    man.push_back(tmp);    
	}
	sort(man.begin(),man.end());
	for(i=0;i<=n;i++){
	    occ[i]=0;
	    //cout << man[i] << ' ';
	}
	for(j=0,i=1;i<n;i++)
	    if(man[i]==man[j])
		continue;
	    else{
		occ[i-j]++;
		j=i;
	    }
	
	occ[i-j]++;
	for(i=1;i<=n;i++)
	    printf("%d\n",occ[i]);
    }	    

}
