#include<cstdio>
#include<iostream>
using namespace std;

int rect[100100],ln[100100],rn[100100];

int n;
int maxx;
int h;
int i;
int r,l,tmr,tml;
int tmp;
int main(){
	while(1){
	cin >> n;
	if(n == 0)
		return 0;
	maxx = 0;
	for(i=0;i<n;i++)
		scanf("%d",&rect[i]);
		
		i=0;
		h = rect[i];
		for(l=i;l>0;l--)
			if(rect[l-1]<h)
				break;
		for(r=i;r<n-1;r++)
			if(rect[r+1]<h)
				break;
		ln[i]=l;
		rn[i]=r;
		tmp = (h*(r-l+1));
		maxx = tmp>maxx?tmp:maxx;	
		
		
	
	//cout << l << ' ' << r << ' ' << i << endl;	
	for(i=1;i<n;i++){
		h = rect[i];
		l=ln[i-1];
		r=rn[i-1]>i?rn[i-1]:i;
		if(rect[i]==rect[i-1]){
			;
		}else if(rect[i] < rect[i-1]){
			for(;l>0;l--)
				if(rect[l-1]<h)
					break;
			for(;r<n-1;r++){
				//cout << 'a' << rect[r+1] << ' ' << r << h;
				if(rect[r+1]<h)
					break;
			}
		}else{
			for(l=i;rect[l-1]>=h;l--);
			for(r=i;rect[r+1]>=h;r++);
		}
		//cout << l << ' ' << r << ' ' << i << endl;
		ln[i]=l;
		rn[i]=r;
		tmp = (h*(r-l+1));
		maxx = tmp>maxx?tmp:maxx;
	}
	cout << maxx << endl;
	
	
	}
return 0;
}