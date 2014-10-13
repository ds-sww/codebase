#include<iostream>
#define MAX 20
using namespace std;
typedef struct element{int x,y,d;}Element;
typedef struct move { int a,b;}MOVE;
char maze[MAX][MAX];
int mark[MAX][MAX];
MOVE mv[4];

int sj,si,tj,ti;
int key=0;

template <class Type> class Stack{
private:
	Type *stk;
	int top;
	int MAXN;
public:
	Stack(int size){MAXN=size;stk=new Type[MAXN];top=-1;}
	~Stack(){delete[]stk;}
	int push(Type x)
	{
		if(top>=MAXN-1)return 1;
		stk[++top]=x;
		return 0;
	}
	int pop(Type*px)
	{
		if(top==-1)return 1;
		*px=stk[top--];
		return 0;
	}
	Type* getTop()
	{
		if(top==-1)return NULL;
		return stk[top];
	}
	int isEmpty() const{return top==-1;}
	int isFull() const{return top==MAXN-1;}
};
Stack<element>s(MAX*MAX);

class Maze{
public:
	void setmove(){
		mv[0].a=-1;mv[0].b=0;
		mv[1].a=0;mv[1].b=1;
		mv[2].a=1;mv[2].b=0;
		mv[3].a=0;mv[3].b=-1;
	}
	void inputmaze(int m,int n){
		int i,j;
		getchar();
		for(i=0;i<=m+1;i++)
			for(j=0;j<=n+1;j++)maze[i][j]='#';
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				cin>>maze[i][j];
			if( maze[i][j]=='S'){si=i;sj=j;}
			if( maze[i][j]=='T'){ti=i;tj=j;}
			} 
			getchar();
		}
	}
	void outputmaze(int m,int n)
	{
		int i,j;
		for(i=0;i<=m+1;i++)
		{
			for(j=0;j<=n+1;j++)cout<<maze[i][j];
			cout<<endl;
		}
	}
	void setmark(int m,int n)
	{
		int i,j;
		for(i=0;i<=m+1;i++)
			for(j=0;j<=n+1;j++)mark[i][j]=0;
	}
	int getmazepath(int m,int n)
	{
		int i,j,k,g,h,t=1;
		Element current;
		current.x=si;
		current.y=sj;
		current.d=-1;
		s.push(current);
		mark[si][sj]=1;
		while(!s.isEmpty())
		{
			s.pop(&current);
			i=current.x;
			j=current.y;
			k=current.d;
			while(k<3)
			{
				
				g=i+mv[++k].a;
				h=j+mv[k].b;
				if(g==ti&&h==tj){
				
					while(!s.isEmpty()){
						s.pop(&current);
						t++;
					}
					cout<<t;
					return 0;
				}
				if((maze[g][h]=='*'||maze[g][h]=='K'||(maze[g][h]=='D'&&key==1))&&mark[g][h]==0)
				{
					if(maze[g][h]=='K')key=1;
					mark[g][h]=1;
					current.x=i;
					current.y=j;
					current.d=k;
					s.push(current);
					i=g;
					j=h;
					k=-1;
				}
			}
		}cout<<-1;return 1;
	}
};
int main()
{
	Maze maze;
	int m,n;
	cin>>m>>n;
	maze.inputmaze(m,n);
	maze.setmark(m,n);
	maze.setmove();
	maze.getmazepath(m,n);
	return 0;
}
