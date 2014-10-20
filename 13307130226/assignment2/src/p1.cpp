#include<cstdio>
#include<iostream>
using namespace std;
int pri;
const int UNABLE = 999999;
char map[25][25];
char tmp[25][25];
int wayy[25][25];
void tmpinit(int n,int m){
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++){
			tmp[i][j]=map[i][j];
			wayy[i][j]=UNABLE;
		}

}
int way(int x1,int y1,int x2,int y2,int count){
	if(pri == 1)
	cout << x1 << ' ' << y1 << x2 << y2 <<"here" << endl;
	if(wayy[x1][y1]<=count)
		return -1;
	wayy[x1][y1] = count;
	if(x1==x2&&y1==y2)
		return 0;
	if(pri == 1)
	cout << x1 << ' ' << y1 << x2 << y2 <<"hereoo" << endl;
	tmp[x1][y1] = '#';
	if(tmp[x1][y1-1]!='#')
		way(x1,y1-1,x2,y2,count+1);
	if(tmp[x1][y1+1]!='#')
		way(x1,y1+1,x2,y2,count+1);
	if(tmp[x1+1][y1]!='#')
		way(x1+1,y1,x2,y2,count+1);
	if(tmp[x1-1][y1]!='#')
		way(x1-1,y1,x2,y2,count+1);
	if(count == 0 && pri == 1){
		for(int i=1;i<15;i++)
			for(int j=1;j<15;j++)
				cout << wayy[i][j] << ((j==14)?'\n':' ');
				
		return wayy[x2][y2]==UNABLE?-1:wayy[x2][y2];
	}
		
	
}
int findway(int n,int m){
	int Kx,Ky,Sx,Sy,Dx,Dy,Tx,Ty;
	int ways,toK,KtoD,DtoT;
	pri = 0;
	Kx=Ky=Sx=Sy=Dx=Dy=Tx=Ty=0;
	ways=-1;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++){
			tmp[i][j]=map[i][j];
			wayy[i][j]=UNABLE;
			switch(map[i][j]){
				case 'K':{Kx=i;Ky=j;break;}
				case 'S':{Sx=i;Sy=j;break;}
	            case 'D':{Dx=i;Dy=j;break;}
                case 'T':{Tx=i;Ty=j;break;}
			}
	}
	//cout << "asfsa" << Sx << Sy << Tx << Ty << endl;
	tmp[Dx][Dy] = '#';
	ways = way(Sx,Sy,Tx,Ty,0);
	if(Sx*Dx*Tx*Kx == 0)
		return ways;
	
	///cout << "aaa" << toK << ' ' << KtoD << ' ' << DtoT << endl;
	tmpinit(n,m);	
	tmp[Dx][Dy] = '#';
	toK = way(Sx,Sy,Kx,Ky,0);
	
	///cout << "aaa" << toK << ' ' << KtoD << ' ' << DtoT << endl;
	if(toK == -1)
		return ways;
	tmpinit(n,m);
	tmp[Dx][Dy] = '*';
	pri = 1;
	KtoD = way(Kx,Ky,Dx,Dy,0);
	
	//cout << "aaa" << toK << ' ' << KtoD << ' ' << DtoT << endl;
	if(KtoD == -1)
		return ways;
	tmpinit(n,m);
	tmp[Dx][Dy] = '*';
	DtoT = way(Dx,Dy,Tx,Ty,0);
	
	//cout << "aaa" << toK << ' ' << KtoD << ' ' << DtoT << endl;
	if(DtoT == -1)
		return ways;
	///cout << "aaa" << toK << ' ' << KtoD << ' ' << DtoT << endl;
	toK = toK + KtoD + DtoT;
	if(ways == -1)
		return toK;
	else
		return (ways>toK)?toK:ways;	
			
}
int main(){
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			cin >> map[i][j];
	for(int i=0;i<25;i++)
		map[i][0]=map[0][i]=map[N+1][i]=map[i][M+1]='#';
	cout << findway(N,M);
	return 0;
}