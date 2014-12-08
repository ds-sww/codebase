#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
vector<string>ru1,ru2;
const unsigned int nfind = string::npos;
int n,rus,pos;
string ini,tmp;
set<string>val;
void dfs(string a){
	for(int i=0;i<rus;++i)
		for(pos=a.find(ru1[i]);pos!=string::npos;pos=a.find(ru1[i],pos+1)){
			tmp = a;
			tmp.replace(pos,ru1[i].size(),ru2[i]);
			if(val.count(tmp)==0){
				++n;
				if(n>1000)return;
				val.insert(tmp);
				//cout << n << " " << tmp << endl;
				dfs(tmp);
				if(n>1000)return;
			}
		}
}

int main(){
	int i,j,g,h;
	int pos[3];
	string tmp,tmpp;
	ru1.clear();
	ru2.clear();
	cin >> tmp;
	ini = tmp.substr(1,tmp.size()-2);
	//cout << "ini  " << ini << endl;
	//st.insert(pair<string,int>(tmp.substr(1,tmp.size()-2),'a'));
	while(cin >> tmp){
		if(tmp=="e")break;
		for(i=j=0;i!=tmp.size();++i)
			if(tmp[i]=='\"')pos[j++]=i;
		//cout <<j<<"aa" << pos[0] <<' '<< pos[3] << endl;
		ru1.push_back(tmp.substr(pos[0]+1,pos[1]-pos[0]-1));
		ru2.push_back(tmp.substr(pos[2]+1,pos[3]-pos[2]-1));
		//cout << *(ru1.end()-1) << "xx" << *(ru2.end()-1) << endl;
	}
	val.clear();n=1;rus = ru1.size();
	val.insert(ini);
	dfs(ini);
	if(n<=1000)
	cout << n << endl;
	else 
	cout << "Too many." << endl; 
	
}