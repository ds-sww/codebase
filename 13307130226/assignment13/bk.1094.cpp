#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,m;
int big[300][300];
int sma[300][300];
char order[300];
int i,j,g,h;
string tmp;
bool nright,occo;
int num_n;
bool check(int nn){
	bool nright=false;
	for(int i='A';i<'A'+n;++i){
		big[i][0]=0;
		for(int j='A';j<'A'+n;++j)
			if(big[i][j]==1)++big[i][0];
		//cout << (char)i << big[i][0] << endl;
	}
	for(int i=n-1;i>=0;--i){
		order[i]=-1;
		for(int j='A';j<'A'+n;++j)
			if(big[j][0]==i)
				order[i]=j;
		if(order[i]==-1){
			nright=true;}
	}
	if(nright)return false;
	else{
		cout << "Sorted sequence determined after "<<nn<<" relations: ";
		for(int i=n-1;i>=0;--i)
			cout << order[i];
		cout <<'.'<< endl;
	}	
	return true;

}
int main(){
while(1){
	cin >> n >> m;
	cin.sync();
	if(n == 0 && m == 0)
		break;
	cout << "mn" << n << m << endl << flush;
	nright = false;
	for(int i='A';i<='Z';++i)
		for(int j='A';j<='Z';++j)
			big[i][j]=sma[i][j]=0;
	for(int i=0;i<m;++i){
		//cout << 't' << i << endl;
		getline(cin,tmp);
		
		if(nright)continue;
		//cin >> tmp;//g<h
		g = tmp[0];
		h = tmp[2];
		big[g][h]=1;
		if(big[h][g]==1){nright=true;cout << "Inconsistency found after "<<i+1<<" relations." << endl;continue;}
		for(int j='A';j<='Z';++j){
			if(big[h][j]==1)big[g][j]=1;
			if(big[j][g]==1)big[j][h]=1;
		}
		nright=check(i+1);
	}
	if(!nright)
		cout <<"Sorted sequence cannot be determined." << endl;
}
return 0;
}