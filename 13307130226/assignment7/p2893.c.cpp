#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#define MAX 2000100
using namespace std;
int n,m,h0;
int i,j,g,h;
int map[MAX];

//merge sort
int countt;
int merge_tmp[MAX];
void merge_sort(int q[],int l,int r){
	if(l+1==r)
		return;
	int mid,now,i,j;
	mid = l+((r-l)>>1);
	if(l+1<mid)
		merge_sort(q,l,mid);
	if(mid+1<r)
		merge_sort(q,mid,r);	
	for(now=0,i=l;i<mid;i++)
		merge_tmp[now++]=q[i];
	i=0;
	j=mid;
	mid=now;
	now=l;
	
	i=0;
	for(;i<mid && j<r;now++)
		if(merge_tmp[i]<=q[j])
			q[now]=merge_tmp[i++];
		else{
			countt += mid-i;
			q[now]=q[j++];
		}
	while(i<mid)
		q[now++]=merge_tmp[i++];
	while(j<r)
		q[now++]=q[j++];		
}

int main(){
	//std::ios_base::sync_with_stdio(false);
	while(1){
		//cin >> m >> n;
		scanf("%d%d",&m,&n);
		if(m == 0 && n == 0)
			return 0;
		h = 0;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++){
			scanf("%d",&g);
			//cin >> g;
			if(g == 0)
				h0=i;
			else
				map[h++]=g;
			}
		countt = 0;
		merge_sort(map,0,m*n-1);
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
