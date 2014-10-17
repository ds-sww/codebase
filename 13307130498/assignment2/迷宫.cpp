//时间效率始终低……总是超时=_=


#include <iostream>

using namespace std;

long static min_times=100000000;
int **steps;

char** Migong;

void copy(char **q,char **p,int nn,int mm,int M,int N){
        int i,j;
        for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                q[i][j]=p[i][j];
    }

void find(char** migong, int mm, int nn,int M,int N,long everytimes,int key,int lastmove){
    int n=nn,m=mm;
    bool ifiskey=0;
    steps[n][m]++;
    int keys[4]={0};
    char **next[4];
    next[0]=next[1]=next[2]=next[3]=NULL;
    if(migong[n][m]=='T'){if(min_times>everytimes)min_times=everytimes;steps[n][m]--;return;}
    if(migong[n][m]=='K')ifiskey=1;
    if(n!=0&&migong[n-1][m]!='#'&&(lastmove!=1||ifiskey==1)&&steps[n-1][m]<=1)
        if(migong[n-1][m]!='D'||(migong[n-1][m]=='D'&&key==1)){
	    if(migong[n-1][m]=='D')key=0;    
            next[0] = migong;
	    if(migong[n-1][m]=='K')keys[0]=1;
	    else keys[0]=key;
        }
    if(n!=N-1&&migong[n+1][m]!='#'&&(lastmove!=0||ifiskey==1)&&steps[n+1][m]<=1)
        if(migong[n+1][m]!='D'||(migong[n+1][m]=='D'&&key==1))
        {    
	    if(migong[n+1][m]=='D')key=0;  
	    next[1] = migong;
	    if(migong[n+1][m]=='K')keys[1]=1;
	    else keys[1]=key;
        }
    if(m!=0&&migong[n][m-1]!='#'&&(lastmove!=3||ifiskey==1)&&steps[n][m-1]<=1)
        if(migong[n][m-1]!='D'||(migong[n][m-1]=='D'&&key==1))
        {    
	    if(migong[n][m-1]=='D')key=0;  
	    next[2] = migong;
	    if(migong[n][m-1]=='K')keys[2]=1;
	    else keys[2]=key;
        }
    if(m!=M-1&&migong[n][m+1]!='#'&&(lastmove!=2||ifiskey==1)&&steps[n][m+1]<=1)
        if(migong[n][m+1]!='D'||(migong[n][m+1]=='D'&&key==1))
        {    
	    if(migong[n][m+1]=='D')key=0;  
	    next[3] = migong;
	    if(migong[n][m+1]=='K')keys[3]=1;
	    else keys[3]=key;
        }
    
    if(next[0]==NULL&&next[1]==NULL&&next[2]==NULL&&next[3]==NULL){everytimes=10000000;steps[n][m]--;return;}
    if(next[0]!=NULL) {lastmove=0;find(next[0],m,n-1,M,N,everytimes+1,keys[0],lastmove);}
    if(next[1]!=NULL) {lastmove=1;find(next[1],m,n+1,M,N,everytimes+1,keys[1],lastmove);}
    if(next[2]!=NULL) {lastmove=2;find(next[2],m-1,n,M,N,everytimes+1,keys[2],lastmove);}
    if(next[3]!=NULL) {lastmove=3;find(next[3],m+1,n,M,N,everytimes+1,keys[3],lastmove);}
    steps[n][m]--;
    return;
}



void get(char element,int *n,int *m,int N,int M)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(Migong[i][j]==element)
                {
                    *n=i;*m=j;
                }
    }    

int main()
{
    int N,M,mm=0,nn=0,key=0;
    int lastmove=5;
    long everytimes=0;
    cin>>N>>M;
    Migong = new char*[N];
    for(int i=0;i<N;i++)
	Migong[i] = new char[M];
    for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	    cin>>Migong[i][j];
    steps = new int *[N];
    for(int i=0;i<N;i++)
	steps[i]=new int[M];
    for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	    steps[i][j]=0;
    int *m=&mm,*n=&nn;
    get('S',n,m,N,M);
    find(Migong,mm,nn,M,N,everytimes,key,lastmove);
    if(min_times==100000000)
	min_times=-1;
    cout<<min_times<<endl;
    return 0;
}

