#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 2000

int P,T;
//s=0
bool a1[10005];
//s=P-1
int ans=0;
bool b1[10005];
int p1,p2,l;
struct aaa{
	 int num;
	 int dis;
	 aaa* next;
};
aaa *x[10005];

struct node{
  int id;
  int w;
  friend bool operator <(node a,node b)
  {
	  return a.w > b.w;
	  
	  } 
}d[10005],dd[10005];

//插入边
void add(int a,int b,int c)
{
    aaa *address_1=new aaa;
    address_1->num=b;
    address_1->dis=c;
    address_1->next=x[a];
    x[a]=address_1;
	aaa *address_2=new aaa;
    address_2->num=a;
    address_2->dis=c;
    address_2->next=x[b];
    x[b]=address_2;
	return;
}
//dijkstra start=0
void dijkstra_1()
{
		memset(a1,0,sizeof(a1));
	priority_queue<node> q;
	for(int i=0;i<10005;i++)
	  {
		d[i].id=i;  
		d[i].w=MAX;
	  }
	  d[0].w=0;
	  q.push(d[0]);
	  while(!q.empty())
	  {
	     node cd=q.top();
	     q.pop();
	     int u=cd.id;
	     if(a1[u]) continue;
	     a1[u]=true;
	     for(aaa* p=x[u];p!=NULL;p=p->next)
	     {
		    int v=p->num;
		    if(!a1[v]&&d[v].w>d[u].w+p->dis)
		    {	 
			   d[v].w=d[u].w+p->dis;
			   q.push(d[v]);
		   }
		}
      }
}


//dijkstra start=P-1
void dijkstra_2()
{
		memset(a1,0,sizeof(a1));
	priority_queue<node> q;
	for(int i=0;i<10005;i++)
	  {
		dd[i].id=i;  
		dd[i].w=MAX;
	  }
	  dd[P-1].w=0;
	  q.push(dd[P-1]);
	  while(!q.empty())
	  {
	     node cd=q.top();
	     q.pop();
	     int u=cd.id;
	     if(a1[u]) continue;
	     a1[u]=true;
	     for(aaa* p=x[u];p!=NULL;p=p->next)
	     {
		    int v=p->num;
		    if(!a1[v]&&dd[v].w>dd[u].w+p->dis)
		    {	 
			   dd[v].w=dd[u].w+p->dis;
			   q.push(dd[v]);
		   }
		}
}
}
void	check_and_print()
{
    for(int i=0;i<P;i++)
      for(aaa* p=x[i];p!=NULL;p=p->next)
        if(p->dis+d[p->num].w+dd[i].w==d[P-1].w)
           ans+=p->dis;
     cout << ans*2<<endl;

}
int main()
{
	for(int i=0;i<10005;i++)
	  x[i]=NULL;


	cin>>P>>T;
	while(T--)
	{
		scanf("%d%d%d",&p1,&p2,&l);
	    add(p1,p2,l);
	}
	dijkstra_1();
	dijkstra_2();
	check_and_print();
    return 0;	
}
/*
 10 15
0 1 580
1 4 90
1 4 90
4 9 250
4 2 510
2 7 600
7 3 200
3 3 380
3 0 150
0 3 100
7 8 500
7 9 620
9 6 510
6 5 145
5 9 160
*/
