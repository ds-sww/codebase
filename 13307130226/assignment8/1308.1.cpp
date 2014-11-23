#include<cstdio>
#include<iostream>
#define MAXN 99999
using namespace std;

int Number[MAXN];
int Father[MAXN];
int n;
int i,j,g,h,k;
bool is_tree;


bool add_father(int father,int son){
	int i,j;
	if(!is_tree)
		return true;
	for(i=0;i<n;i++)
		if(Number[i]==son)
			break;
	if(i==n){
		Number[n]=son;
		Father[n++]=-1;
	}
	if(Father[i]!=-1 && Father[i]!=father)
		return false;
	else
		Father[i]=father;
	for(i=0;i<n;i++)
		if(Number[i]==father)
			return true;
	Number[n]=father;
	Father[n++]=-1;
	return true;
}
int get_pos(int num){
	int i;
	for(i=0;i<n;i++)
		if(Number[i]==num)
			return i;
}
int get_father(int son,int time=0){
	if(time>n)
		return -1;
	if(Father[son]==-1)
		return Number[son];
	Father[son]=get_father(get_pos(Father[son]),time+1);
	//cout << "father " << Father[son] << ' ' << son << endl; 
	return Father[son];
}
bool check_father(){
	int i,j,root;
	j=0;
	for(i=0;i<n;i++)
		if(Father[i]==-1){
			++j;
			root = i;
	}
	if(j!=1)
		return false;
	for(i=0;i<n;i++)
		if(i!=root)
			if(get_father(i)!=Number[root])
				return false;
	return true;
}
void pp(){
	int i;
	cout << endl;
	for(i=0;i<n;i++)
		printf("%4d",Father[i]);
	cout << endl;
	for(i=0;i<n;i++)
		printf("%4d",Number[i]);
	//cout << endl;
	printf("\n%d\n",is_tree);

}
int main(){
	k=0;
	while(1){
		is_tree=true;
		n=0;
		while(1){
			scanf("%d%d",&i,&j);
			if((i<0)&&(j<0))
				return 0;
			if((i==0)&&(j==0))
				break;
			if(!add_father(i,j)){
				is_tree=false;
			}
			//pp();
		}
		if(!is_tree){
			//printf("Case %d is not a tree.\n",++k);
			cout << "Case " << ++k << " is not a tree." << endl;
			continue;
		}
		if(check_father()){
			//printf("Case %d is a tree.\n",++k);
			cout << "Case " << ++k << " is a tree." << endl;
			continue;
		}else{
			//printf("Case %d is not a tree.\n",++k);
			cout << "Case " << ++k << " is not a tree." << endl;
			continue;
		}
	}
}