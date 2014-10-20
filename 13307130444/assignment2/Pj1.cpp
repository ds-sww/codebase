#include"Stack.h"//其实没有用到Stack，用到的是队列
#include<iostream>
#include<queue>
#define MAX 20
using namespace std;
typedef struct element{int x,y,d;}Element;
typedef struct move { int a,b;}MOVE;
char maze[MAX][MAX];
int mark[MAX][MAX][2];
MOVE mv[4];


queue<element>Q;
class Maze{
private:
	int sj,si,tj,ti;
	int key;
public:
	void setmove(){
		mv[0].a=-1;mv[0].b=0;
		mv[1].a=0;mv[1].b=1;
		mv[2].a=1;mv[2].b=0;
		mv[3].a=0;mv[3].b=-1;
	}
	void inputmaze(int m,int n){
		int i,j;
		//cout<<"Input maze"<<endl;
		getchar();
		for(i=0;i<=m+1;i++)
			for(j=0;j<=n+1;j++)maze[i][j]='#';
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				scanf("%c",&maze[i][j]);
			if( maze[i][j]=='S'){si=i;sj=j;}
			if( maze[i][j]=='T'){ti=i;tj=j;}
			} 
			getchar();
		}
	}
	void outputmaze(int m,int n)
	{
		int i,j;
		//cout<<"outputmaze:"<<endl;
		for(i=0;i<=m+1;i++)
		{
			for(j=0;j<=n+1;j++)cout<<maze[i][j];
			cout<<endl;
		}
	}
	void setmark(int m,int n)
	{
		key=0;
		int i,j;
		for(i=0;i<=m+1;i++)
			for(j=0;j<=n+1;j++){mark[i][j][0]=0;mark[i][j][1]=0;}
	}
	int getmazepath(int m,int n)
	{
		Element current,nbr;
		current.x=si;
		current.y=sj;
		current.d=-1;//不明白
		mark[si][sj][0]=2;mark[si][sj][1]=0;
		do{
			for(int i=0;i<4;i++){
				nbr.x=current.x+mv[i].a;
				nbr.y=current.y+mv[i].b;
				if(
					(mark[nbr.x][nbr.y][0]==0||(mark[nbr.x][nbr.y][1]==0&&mark[current.x][current.y][1]==1))
					&&(
					maze[nbr.x][nbr.y]=='T'||maze[nbr.x][nbr.y]=='S'||maze[nbr.x][nbr.y]=='*'||maze[nbr.x][nbr.y]=='K'||(maze[nbr.x][nbr.y]=='D'&&mark[current.x][current.y][1]==1)
					))
				{//进入，标记
					
					 
					mark[nbr.x][nbr.y][0]=1+mark[current.x][current.y][0];
					if((nbr.x==ti&&nbr.y==tj))break;
					Q.push(nbr);
					if(mark[current.x][current.y][1]==1)mark[nbr.x][nbr.y][1]=1;
			        if(maze[nbr.x][nbr.y]=='K')mark[nbr.x][nbr.y][1]=1;
				}
				
				
			}
			
			if((nbr.x==ti&&nbr.y==tj))
						break;
			if(Q.empty())return false;
			nbr=current;
			current=Q.front();
			Q.pop();
			
		}while(true);
			
		int plen=mark[nbr.x][nbr.y][0]-2;cout<<plen;
		return plen;
	}
};//@_@

int main()
{
	Maze maze;
	int m,n;
	cin>>m>>n;
	maze.inputmaze(m,n);
	maze.setmark(m,n);
	maze.setmove();
	maze.getmazepath(m,n);
	//getchar();
	//getchar();
	return 0;
}

