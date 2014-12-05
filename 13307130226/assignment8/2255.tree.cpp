#include<iostream>
#include<string>
#define MAXN 9999
using namespace std;

class tree{
private:
	char st[MAXN];
	int st_n;
	struct node{
		char name;
		node *father,*l,*r;
		/*node(){
			father=l=r=NULL;
		}*/
		node(char a='\0'){
			father=l=r=NULL;
			name=a;
		}
		void clear(){
			if(l!=NULL) l->clear();
			if(r!=NULL) r->clear();
			delete(l);delete(r);
			father=l=r=NULL;
			name='\0';
		}
	}*root;
void p_pre(node *a){
	cout << a->name;
	if(a->l!=NULL)p_pre(a->l);
	if(a->r!=NULL)p_pre(a->r);
}
void p_post(node *a){
	if(a->l!=NULL)p_post(a->l);
	if(a->r!=NULL)p_post(a->r);
	cout << a->name;
}
public:
	tree(){
		st_n = 0;
		root=NULL;
	}
	~tree(){
		delete(root);
	}
	void print_pre(){
		cout << "PRE: " << endl;
		p_pre(root);
		cout << endl;
	}
	void print_post(){
		//cout << "POST: " << endl;
		p_post(root);
		cout << endl;
	}
	void set_by_prepost(string pre,string post){
		node *now,*tmp;
		int i,j;
		if(pre.size()==0)return;
		if(root!=NULL)root->clear();
		else root=new node;
		now = root;st_n=0;
		for(i=j=0;i<pre.size();){
			st[++st_n]=pre[i];
			now->r = tmp = new node(pre[i++]);
			tmp->father=now;
			now=tmp;
			while(i<pre.size()&&now->name!=post[j]){
				st[++st_n]=pre[i];
				now->l = tmp = new node(pre[i++]);
				tmp->father = now;
				now = tmp;
			}
			while(j<post.size()&&st[st_n]==post[j]){
				while(now->name!=post[j])now=now->father;
				--st_n;++j;
			}
		}
		tmp = root;
		root = root->r;
		delete(tmp);		
	}

};

int main(int argn,char* argc[]){
	string a,s;
	tree mine;
	while(cin >> a >> s){
	mine.set_by_prepost(a,s);
	//mine.print_pre();
	mine.print_post();	
	}	
	return 0;
}