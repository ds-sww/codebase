#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#define MAXN 101000
using namespace std;
class coww{
public:
	int high,pos;
};
bool cmp(const coww& a,const coww& b)
{
	if(a.high>b.high)
		return true;
	else if(a.high<b.high)
		return false;
	else if(a.pos>b.pos)
		return true;
	else
		return false;
}
vector<coww> sort_cow;
list<coww> list_cow;
list<coww>::iterator iter;
int sort_n;
coww cow_tmp;
int con[MAXN];
int l[MAXN*3],r[MAXN*3];
int nlr,lrn;
int n;
int now;
int tmppos;
int i,j,g,h;

int get_int(){
	char a;
	int tmp=0;
	while((a=getchar())<='9' && a>='0')
		tmp=tmp*10+a-'0';
	return tmp;
}

int main(){
	n=get_int();
	sort_cow.clear();
    //scanf("%d",&n);
    for(i=0;i<n;i++){
		//cow[i]=get_int();
		con[i]=0;
		j=get_int();
		cow_tmp.high=j;
		cow_tmp.pos=i;
		sort_cow.push_back(cow_tmp);		
	}
	//scanf("%d",&cow[i]);
	sort(sort_cow.begin(),sort_cow.end(),cmp);
	list_cow.clear();
	for(i=0;i<n;i++)
		list_cow.push_back(sort_cow[i]);
	nlr=1;lrn=0;
	l[0]=0;
	r[0]=n;
	//sort_n =0;
	while(lrn!=nlr){
		//cout << "ll "<<l[lrn] << ' ' << r[lrn] << ' ';
		for(iter=list_cow.begin();;++iter){
			tmppos=(*iter).pos;
			if(tmppos>=l[lrn] && tmppos<r[lrn])
				break;
		}
		//cout << 'c' << tmppos << endl;
		con[tmppos]=r[lrn]-tmppos-1;
		//cout << 'c' << tmppos << 'r' << r[lrn]<<endl;
		if(l[lrn]<tmppos){
			l[nlr]=l[lrn];
			r[nlr++]=tmppos;
		}
		++tmppos;
		if(tmppos<r[lrn]){
			l[nlr]=tmppos;
			r[nlr++]=r[lrn];			
		}
		//sort_cow[i].pos=-1;
		list_cow.erase(iter);
		++lrn;	
	}
	j=0;
    for(i=0;i<n;i++)
	j+=con[i];
    printf("%d\n",j);
    return 0;
}
