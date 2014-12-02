#include<iostream>
#include<string>
#include<vector>
using namespace std;

string pre,post;
class tree{
public:
	char name;
	tree* father;
	vector<tree*> sons;
	tree(){
		name='0';
		father=NULL;
		sons.clear();
	}
	tree(char a){
		name=a;
		father=NULL;
		sons.clear();
	}
	~tree(){
		for(int i=0;i<sons.size();i++)
			delete(sons[i]);
		sons.clear();
		//cout << "delete " << name << endl;
	}
}*root,*now,*tmp;
int i,j,g,h;
int n;
long long m;

void make_pre(tree* now){
	cout << now->name;
	for(int i=0;i<now->sons.size();i++)
		make_pre(now->sons[i]);
}
void make_post(tree* now){
	for(int i=0;i<now->sons.size();i++)
		make_post(now->sons[i]);
	cout << now->name;
}
long long ccc(int a,int s){
	long long tmp;
	int i;
	s = (a-s<s)?a-s:s;
	tmp=1;
	for(i=0;i<s;++i)
		tmp *= a-i;
	for(i=s;i>1;--i)
		tmp /= i;
	return tmp;		
}
void count(tree* now){
	m *= ccc(n,now->sons.size());
	for(int i=0;i<now->sons.size();i++)
		count(now->sons[i]);	
}


int main(){
	while(1){
	cin >> n;
	if(n==0)
		return 0;
	cin >> pre >> post;
	delete(root);
	root = new tree;
	root->name = pre[0];
	now = root;
	for(j=0,i=1;i<pre.size();i++){
		while(j<post.size()&&post[j]==now->name){
			now=now->father;
			++j;
		}
		tmp = new tree(pre[i]);
		tmp->father=now;
		now->sons.push_back(tmp);
		now=tmp;
	}
	/*
	cout << "PRE:" << endl;
	make_pre(root);
	cout << endl << "post:" << endl;
	make_post(root);
	cout << endl;  */
	m=1;
	count(root);
	cout << m << endl;
	
	}
	return 0;
}