#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int n,m,h0;
int i,j,g,h;
vector<int> map;

//merge sort
int countt;
vector<int> merge_tmp;
void merge_sort(vector<int>::iterator l,vector<int>::iterator r){
	if(l==r-1)
		return;
	vector<int>::iterator i,j,mid,now;
	mid = l+((r-l)>>1);
	merge_sort(l,mid);
	merge_sort(mid,r);
	merge_tmp.clear();
	for(i=l;i!=mid;i++)
		merge_tmp.push_back(*i);
	for(i=merge_tmp.begin(),j=mid,now=l;i!=merge_tmp.end() && j!=r;now++){
		if(*i <= *j){
			*now = *i;
			i++;
		}else{
			*now = *j;
			countt += merge_tmp.end()-i;
			j++;
		}
	}
	while(i!=merge_tmp.end())
		*(now++)=*(i++);
	while(j!=r)
		*(now++)=*(j++);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	while(1){
		scanf("%d%d",&m,&n);
		//cin >> m >> n;
		if(m == 0 && n == 0)
			return 0;
		map.clear();
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
			//cin >> g;
			scanf("%d",&g);
			if(g == 0)
				h0=i;
			else
				map.push_back(g);
			}
		countt = 0;
		merge_sort(map.begin(),map.end());
		n &= 1;
		h0 = (m-h0-1)&1;
		//cout << "count" << countt << endl;
		countt &= 1;
		if(n==1){
			if(countt==0)
				printf("YES\n");
				//cout << "YES" << endl;
			else
				printf("NO\n");
				//cout << "NO" << endl;
		}
		if(n==0){
			if(countt ^ h0 == 0)
				printf("YES\n");
				//cout << "YES" << endl;
			else
				printf("NO\n");
				//cout << "NO" << endl;
		}
	}

}
