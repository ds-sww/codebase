#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,head,tail,sx,sy,ex,ey,a[111][111],hash[111][111][2];
const int dx[4]={-1,0,0,1};
const int dy[4]={0,-1,1,0};
struct rec
{
   int x,y,step,opt;
}q[1111111];
char c;
int main()
{
//    freopen("maze.in","r",stdin);
//    freopen("maze.out","w",stdout);
    scanf("%d %d",&n,&m);
    c=getchar();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++) 
        {
            c=getchar();
            if (c=='*') a[i][j]=0;
               else if (c=='#') a[i][j]=1;
                       else if (c=='D') a[i][j]=2;
                               else if (c=='K') a[i][j]=3;
                                       else if (c=='S') { a[i][j]=4; sx=i; sy=j; }
                                               else { a[i][j]=5; ex=i; ey=j; }
        }
        c=getchar();
    }
    head=1; tail=1; q[1].x=sx; q[1].y=sy; q[1].opt=0; q[1].step=0;
    hash[sx][sy][0]=1;
    bool flag=0;
    int ans=-1;
    while (head<=tail)
    {
          for (int i=0;i<4;i++)
          {
              int tx=q[head].x+dx[i];
              int ty=q[head].y+dy[i];
              if (tx>=0 && tx<n && ty>=0 && ty<m && a[tx][ty]!=1)
              {
                  if (a[tx][ty]==2 && q[head].opt==0) continue;               
                  if (a[tx][ty]==5) { flag=1; ans=q[head].step+1; break; }
                  if (hash[tx][ty][q[head].opt]) continue;
                  q[++tail].x=tx;q[tail].y=ty; q[tail].opt=(a[tx][ty]==3) | q[head].opt; q[tail].step=q[head].step+1;
                  hash[tx][ty][q[tail].opt]=1;
              }
          }
          if (flag) break;
          head++;
    }
    printf("%d\n",ans);
    return 0;
}