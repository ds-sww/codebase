#include<iostream>
#include<string>
using namespace std;

int gre[300][300];
int val[300];
int n,m;
string tmp;
string ans;
bool nright;
bool nn;

bool check(int times){
	for(int i=0;i<n;++i)val[i]=0;
	for(int i='A';i<'A'+n;++i){
		gre[i][0]=0;
		for(int j='A';j<'A'+n;++j)
			if(gre[i][j]==1)
				++gre[i][0];
		val[gre[i][0]]=i;
	}
	for(int i=0;i<n;++i)
		if(val[i]==0)return false;
	ans = "Sorted sequence determined after ";
	ans +=(char)(times+'1');
	ans +=" relations: ";
	for(int i=n-1;i>=0;--i)
		ans +=(char)val[i];
	ans += '.';
	return true;
}

int main(){
while(1){
	cin >> n >> m;
	if(n == 0 && m == 0)
		break;
	for(int i='A';i<'A'+n;++i)
		for(int j='A';j<'A'+n;++j)
			gre[i][j]=0;
	nright=nn=false;
	ans = "Sorted sequence cannot be determined.";
	for(int ii=0;ii<m;++ii){
		cin >> tmp;
		if(nn)continue;
		int a,b; //a<b
		a = tmp[0];
		b = tmp[2];
		if(gre[b][a]==1){ans = "Inconsistency found after ";ans+=(char)(ii+'1');ans+=" relations.";nright=true;nn=true;continue;}
		gre[a][b]=1;
		for(int i='A';i<'A'+n;++i){
			if(gre[b][i]==1)gre[a][i]=1;
			if(gre[i][a]==1)gre[i][b]=1;
		}
		if(!nright)
			nright=check(ii);
	}
	cout << ans << endl;
}
return 0;
}