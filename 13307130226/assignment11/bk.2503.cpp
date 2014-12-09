#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAXN 100100 


#define hash_size 0xffffff
class hash_map{//发现删除好麻烦先不考虑了
public:
	unsigned int n;
	
	string key[MAXN]; //从1开始装
	unsigned int keyh[MAXN];
	string val[MAXN];
	unsigned int hash[hash_size+10];  //莫名其妙开不下...放弃了
	unsigned int next[MAXN];
	hash_map(){
		cout <<"c";
		n = 0;
		//keyh[0]=0;
		//key[0]="";
		//val[0]="";
		cout << "cedn";
	}
	/*
	unsigned int BKDR(string& stt){
		unsigned int hash;
		hash = 0;
		for (string::iterator it=stt.begin(); it!=stt.end(); ++it)
			hash = (hash * 31 + *it)&hash_size;
		return hash;
	}
	void insert(string& k,string& v){
		unsigned int ha;
		key[++n]=k;
		val[n]=v;
		ha = BKDR(k);
		keyh[n]=ha;
		next[n]=hash[ha];
		hash[ha]=n;
	}
	int find(string& a){
		unsigned int ha,now;
		ha = BKDR(a);
		if(hash[ha]==0||hash[ha]>n)
			return 0;
		now = hash[ha];
		while(now!=0&&now<=n&&keyh[now]==ha){
			if(a==key[now])
				return now;
			now = next[now];
		}
		return 0;
	}
	string get_val(string& a){
		return val[find(a)];
	}*/
};

int main(){
	cout << "begin";
	hash_map ma;
	cout << "size " << ma.n << endl;
	//ma.insert("hh","aa");
	//cout << ma.find("hh") << endl;
	//cout << ma.find("aa") << endl;
}