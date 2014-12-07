#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
//#include <hash_map> 
#include <ext/hash_map> 
using namespace __gnu_cxx;
using namespace std;
vector<string>ru1,ru2;
hash_map<string,char>st;
const unsigned int nfind = string::npos;
int n;
int main(){
	int i,j,g,h;
	int pos[3];
	string tmp,tmpp;
	ru1.clear();
	ru2.clear();
	cin >> tmp;
	st.clear();
	st[tmp.substr(1,tmp.size()-2)]='a';
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
	while(1){
		bool ncha;
		int end;
		ncha = true;
		for(hash_map<string,char>::iterator q=st.begin();q!=st.end();++q){
			tmpp = q->first;
			for(i=0;i<ru1.size();i++){
				for(j=tmpp.find(ru1[i]);j!=nfind;j=tmpp.find(ru1[i],j+1)){
					tmp = tmpp;
					tmp = tmp.replace(j,ru1[i].size(),ru2[i]);
					if(st.count(tmp)==0)ncha = false;
					else continue;
					st[tmp]='a';
					//st.insert(pair<string,int>(tmp,'a'));
					//cout << "q " << *q << " " << tmp<<endl;
				}
			if(st.size()>1000)goto here;
			}
			//cout << "now";
		}
		//cin >> tmp;
		if(ncha||st.size()>1000)break;
	}
here:	
	if(st.size()<=1000)cout << st.size()<<endl;
	else cout << "Too many." << endl;
	return 0;
}