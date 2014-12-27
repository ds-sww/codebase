#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const long long  MAXX=0x7ffffffffff;
const long long  MINN=-MAXX;
long long T,N,M;
long long i,j,g,h;
long long l,r,mid,countt,countl,tmp;
long long num;


#define cal(i,j) ((i)*(i) + 100000*(i) + (j)*(j) - 100000*(j) + (i)*(j))
  /*
long long count_smaller(long long j,long long ans,long long N){
	long long tmp;
	tmp = 0;
	for(i=1;i<=N;++i){
		if(cal(i,j) < ans){
			++tmp;
			//cout << cal(i,j) << ' ' << i << ' ' << j << endl;
		}
	}
	return tmp;
}
   */
long long count_smaller(long long j,long long ans,long long N){
	long long l,r,mid;
	long long tmp1,tmp2;
	long long a,b,c,d;
	if(cal(1,j)>=ans)
		return 0;
	if(cal(N,j)<ans)
		return N;
	b = 100000+j;
	c = j*j - 100000*j-ans;
	d = b*b - 4*c;
	mid = (sqrt((double)d)-b)/2;
	//cout << j << " " << ans << " " << N << endl;
	//cout <<"mid  "<< mid << ' '<<d<< ' ' << sqrt(d) << endl;
	l = mid-5<1?1:mid-5;
	r = mid+5>N?N:mid+5;	
	//l=1;r=N;
	while(1){
		mid = (l+r)>>1;
		tmp1 = cal(mid,j);
		tmp2 = cal(mid+1,j);
		//cout << l << " lr " << r << " " << tmp1 << ' ' << tmp2  << "j " << j << " ans "<< ans << endl;
		if(tmp1 < ans && tmp2 >=ans)
			return mid;
		else if(tmp1 >= ans)
			r = mid;
		else 
			l = mid;
	}
}
long long count_smallerr(long long j,long long ans,long long N){
	long long l,r,mid;
	long long tmp1,tmp2;
	if(cal(1,j)>=ans)
		return 0;
	if(cal(N,j)<ans)
		return N;
	l=1;r=N;
	
	while(1){
		mid = (l+r)>>1;
		tmp1 = cal(mid,j);
		tmp2 = cal(mid+1,j);
		//cout << l << " lr " << r << " " << tmp1 << ' ' << tmp2  << "j " << j << " ans "<< ans << endl;
		if(tmp1 < ans && tmp2 >=ans)
			return mid;
		else if(tmp1 >= ans)
			r = mid;
		else 
			l = mid;
	}
}


int main(){
cin >> T;
while(T--){
	cin >> N >> M;
	--M;
	l=cal(1,1);
	r=cal(1,1);
	l = cal(1,N);
	r = MAXX;
	if(M == 0)
		mid = l;
	else
	while(1){
		mid = (l+r)/2;		
		countt = 0;		
		for(j=1;j<=N;j++){
			//cout << "ini " << count_smallerr(j,mid,N) << endl;
			//cout << "tit " << count_smaller(j,mid,N) << endl;
			countt += count_smaller(j,mid,N);		
		}
		countl = 0;		
		for(j=1;j<=N;j++){
			countl += count_smaller(j,mid+1,N);		
		}
		if(countt <= M && countl > M){
			break;
		}
		if(countt <= M){
			l = mid;
		}
		if(countt > M){
			r = mid;
		}
		if(r-l==1){
			if(countt > M){
				--mid;break;
			}
			if(countt <= M){
				break;
			}
		}
	}	
	cout<<	mid << endl;
}
return 0;
}