/*
 * a.cpp
 *
 *  Created on: 2014.9.29
 *      Author: ihciah
 */
#include<iostream>
using namespace std;
int N,M;
int A,B;
int TA, TB;
int SA, SB;
char **p;
int STEP=0;
void dg(int x, int y, int step, bool key);
void pd(int x, int y, int a, int b, int step, bool key);
void readimap(){
	cin>>N>>M;
	p=new char *[N];
	for(int i=0;i<N;i++)
		p[i]=new char[M];
	for(int a=0;a<N;a++)
		for(int b=0;b<M;b++){
			cin>>p[a][b];
			if (p[a][b] == 'S'){
				SA = a;
				SB = b;
			}
			else if (p[a][b] == 'T'){
				TA = a;
				TB = b;
			}
		}
}
void pd(int x, int y,int a,int b, int step, bool key){
	char ori = p[a][b];
	if (key)
		p[a][b] = '.';
	else
		p[a][b] = ',';
	if (p[x][y] == '*'){
		dg(x, y, step + 1, key);
	}
	if (p[x][y] == 'T'){
		dg(x, y, step + 1, key);
	}
	if (p[x][y] == 'K'){
		dg(x, y, step + 1, 1);
	}
	if (p[x][y] == 'D'){
		if (key){
			dg(x, y, step + 1, 1);
		}
	}
	if (key)
		if (p[x][y] == ',')
			dg(x, y, step + 1, key);
	p[a][b] = ori;
}
void dg(int x,int y,int step,bool key){
	if (STEP < step&&STEP != 0)
		return;
	if (x == TA&&y == TB){
		STEP = (step < STEP || STEP == 0) ? step : STEP;
	}
	else{
		if (y - 1 >= 0)
			pd(x, y - 1,x,y,step,key);
		if (y + 1 < M)
			pd(x,y + 1,x,y,step,key);
		if (x- 1 >= 0)
			pd(x-1, y, x, y, step, key);
		if (x + 1 <N)
			pd(x+1, y, x, y, step, key);

	}

}


int main(){
	readimap();
	dg(SA, SB, 0, false);
	cout << (STEP==0?-1:STEP);
	return 0;
}
/*
7 8
* * * * * * S *
* # # * # # # #
* * * * * # # #
# # # # * # # #
# # * * * # # #
# # * # # # # #
# K * D T # # #

4 4
# # # S
# D K *
# * # #
* * * T
*/
