#include<iostream>
#include<map>
using namespace std;

map<int,int> node;
map<int,int>::iterator tmp;
int i,j,g,h,k,n,root;
bool is_tree;

int get_father(int son,int time=0){
	if(time>n){
		is_tree=false;
		return 0;
	}
	if(node[son]==-1){
		root=son;
		return son;
	}
	return node[son]=get_father(node[son],time+1);
}

void check(){
	n=node.size();
	for(tmp=node.begin();tmp!=node.end();++tmp){
		get_father(tmp->first);
		if(!is_tree)
			return;
	}
	for(tmp=node.begin();tmp!=node.end();++tmp)
		if(tmp->first==root)
			continue;
		else if(tmp->second!=root){
			is_tree=false;
			return;
		}
}

int main(){
	k=0;
	while(1){
		++k;
		node.clear();
		is_tree=true;
		while(1){
			cin >> i >> j;
			if(j<0)
				return 0;
			if(i==0 && j==0)
				break;
			tmp = node.find(i);
			if(tmp==node.end())
				node[i]=-1;			
			tmp = node.find(j);
			if(tmp==node.end())
				node[j]=i;
			else if(node[j]==-1)
				node[j]=i;
			else
				is_tree=false;
			
		}
		if(!is_tree){
			 cout<<"Case "<<k<<" is not a tree."<<endl;  
			 continue;
		}else{
		check();
		if(is_tree)
			cout<<"Case "<<k<<" is a tree."<<endl;  
		else
			cout<<"Case "<<k<<" is not a tree."<<endl;  }
	}
}