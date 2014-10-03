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
char** copy(char **s){
	char **r;
	r = new char *[N];
	for (int i = 0; i<N; i++)
		r[i] = new char[M];
	for (int a = 0; a<N; a++)
		for (int b = 0; b<M; b++)
			r[a][b] = s[a][b];
	return r;
}

void dg(int x,int y,int step,bool key,char** s){
	if (STEP < step&&STEP != 0)
		return;
	//cout << x << ',' << y << endl;
	if (x == TA&&y == TB){
		STEP = (step < STEP || STEP == 0) ? step : STEP;
	}
	else{
		if (y - 1 >= 0){
			if (s[x][y - 1] == '*' || s[x][y - 1] == 'T'){
				s[x][y] = '.';
				dg(x, y - 1, step+1, key,copy(s));
			}
			if (s[x][y - 1] == 'K'){
				s[x][y] = '.';
				dg(x, y - 1, step+1, 1,copy(s));
			}
			if (s[x][y - 1] == 'D'){
				if (key){
					s[x][y] = '.';
					dg(x, y - 1, step+1, 1, copy(s));
				}
			}
		}
		//
		if (y + 1 <M){
			if (s[x][y + 1] == '*' || s[x][y + 1] == 'T'){
				s[x][y] = '.';
				dg(x, y+1, step+1,key,copy(s));
			}
			if (s[x][y + 1] == 'K'){
				s[x][y] = '.';
				dg(x, y + 1, step+1, 1,copy(s));
			}
			if (s[x][y + 1] == 'D'){
				if (key){
					s[x][y] = '.';
					dg(x, y + 1, step+1, 1, copy(s));
				}
			}
		}
		//
		if (x- 1 >= 0){
			if (s[x - 1][y] == '*' || s[x - 1][y] == 'T'){
				s[x][y] = '.';
				dg(x-1, y, step+1, key, copy(s));
			}
			if (s[x-1][y] == 'K'){
				s[x][y] = '.';
				dg(x-1,y, step+1, 1, copy(s));
			}
			if (s[x-1][y] == 'D'){
				if (key){
					s[x][y] = '.';
					dg(x-1, y, step+1, 1, copy(s));
				}
			}
		}
		if (x + 1 <N){
			if (s[x + 1][y] == '*' || s[x + 1][y] == 'T'){
				s[x][y] = '.';
				dg(x+1, y, step+1, key, copy(s));
			}
			if (s[x+1][y] == 'K'){
				s[x][y] = '.';
				dg(x+1,y, step+1, 1, copy(s));
			}
			if (s[x+1][y] == 'D'){
				if (key){
					s[x][y] = '.';
					dg(x + 1, y, step+1, 1, copy(s));
				}
			}
		}

	}

}


int main(){
	readimap();
	dg(SA, SB, 0, false, p);
	cout << (STEP==0?-1:STEP);
	return 0;
}
/*
7 8
* * * * * * S *
K # # * # # # #
* * * * * # # #
# # # # * # # #
# # * * * # # #
# # * # # # # #
# * # D T # # #

4 4
# # # S
# D K *
# * # #
* * * T
*/
