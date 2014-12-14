    #include<iostream>  
    #include<cstdio>  
    #include<map>  
    #include<cstring>  
    #include<cmath>  
    #include<vector>  
    #include<queue>  

    #define N 130  
    #define maxn 100005  
    #define mem(a,b) memset(a,b,sizeof(a))  
    #define mp(a,b) make_pair(a,b)  
    using namespace std;  
    const long long hash1=26;  
    struct HASH
    {  
        long long h1;  
        HASH(){}  
        HASH(long long _h1):h1(_h1){}  
    }h[N][N];  
    int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];    
    int cmp(int *r,int a,int b,int l)    
    {return r[a]==r[b]&&r[a+l]==r[b+l];}    
    void da(const int *r,int *sa,int n,int m)
    {    
        int i,j,p,*x=wa,*y=wb,*t;     
        for(i=0;i<m;i++) Ws[i]=0;     
        for(i=0;i<n;i++) Ws[x[i]=r[i]]++;     
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1];     
        for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;     
        for(j=1,p=1;p<n;j*=2,m=p){     
            for(p=0,i=n-j;i<n;i++) y[p++]=i;     
            for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;     
            for(i=0;i<n;i++) wv[i]=x[y[i]];     
            for(i=0;i<m;i++) Ws[i]=0;     
            for(i=0;i<n;i++) Ws[wv[i]]++;     
            for(i=1;i<m;i++) Ws[i]+=Ws[i-1];     
            for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];     
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)     
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;     
        }     
        return;     
    }    
    int sa[maxn],Rank[maxn],height[maxn];    
    void calheight(const int *r,int *sa,int n){    
        int i,j,k=0;    
        for(i=1;i<=n;i++) Rank[sa[i]]=i;   
        for(i=0;i<n;height[Rank[i++]]=k)    
            for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);    
        return;    
    }      
    int tot,r[maxn],cnt;  
    char str[N][N];  
    int main()
    {  
        int many,n,m;  
        scanf("%d",&many);  
        for(int z=1;z<=many;z++)
        {  
            scanf("%d%d",&n,&m);  
            for(int i=0;i<n;i++) scanf("%s",str[i]);  
            mem(h,0);  
            long long ans=0;  
            for(int w=1;w<=m;w++)
            {  
                tot=1;cnt=0;  
                map<long long,int> map;  
                map.clear();  
                for(int i=0;i<n;i++)
                    for(int j=0;j+w-1<m;j++){  
                        h[i][j].h1=h[i][j].h1*hash1+str[i][j+w-1]-'A';  
                        if(map.find(h[i][j].h1)==map.end())  
                            map.insert(mp(h[i][j].h1,tot++));  
                    }       
                for(int j=0;j+w-1<m;j++){      
                    for(int i=0;i<n;i++){              
                        r[cnt++]=map[h[i][j].h1];  
                    }  
                    r[cnt++]=tot++;  
                }  
                r[cnt]=0;  
                da(r,sa,cnt+1,tot);  
                calheight(r,sa,cnt);  
                long long tmp=(n*(n+1)/2)*(m-w+1);  
                for(int i=1;i<=cnt;i++)
                    tmp-=height[i];
                ans+=tmp;     
            }  
            printf("Case #%d: %lld\n",z,ans);  
        }  
        return 0;  
    }  
