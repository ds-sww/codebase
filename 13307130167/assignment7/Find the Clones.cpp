#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

class DNA{
public:
    DNA()   {  memset(dna_cnt, 0 , 4*sizeof(int)); mark=0; }
    int dna_cnt[4];
    int mark;
};
/*
bool dna_equ(int a[], int b[]){
    int m=0;
    while (a[m]==b[m])  m++;
    return (m>=4);
}
*/

bool operator < (const DNA a,const DNA b){
    int i=0;
    for (i =0 ; i <4; i++){
        if (a.dna_cnt[i]<b.dna_cnt[i])      return true;
        else if (a.dna_cnt[i]==b.dna_cnt[i])    continue;
        else return false;
    }
}

bool com(DNA a,DNA b){
    return (a<b);
}

bool operator==(const DNA a, const DNA b){
    int i=0;
    while(i<=3&&a.dna_cnt[i]==b.dna_cnt[i])       i++;
    return (i==4);
}

int main()
{
    int peo_num , dna_len;
    cin>>peo_num>>dna_len;
    while (peo_num!=0&&dna_len!=0){
        DNA *dna_grp=new DNA[peo_num];
        char seq[21];
        for (int i=0; i< peo_num; i++){
                scanf("%s",seq);
         for (int j =0 ; j <dna_len;j++){
                switch(seq[j]){
                  case 'A' : dna_grp[i].dna_cnt[0]+=1<<j;  break;
                  case 'C' : dna_grp[i].dna_cnt[1]+=1<<j;  break;
                  case 'G' : dna_grp[i].dna_cnt[2]+=1<<j;  break;
                  case 'T' : dna_grp[i].dna_cnt[3]+=1<<j;  break;
                  default : continue;
                }
            }
        }
        sort(dna_grp,dna_grp+peo_num,com);
        int *com_r=new int[peo_num];
        memset(com_r,0, peo_num*sizeof(int));
        int p;
        int q;
        int same_cnt=0;
        for (p=0,q=1;p<peo_num;p+=same_cnt+1,q=p+1,same_cnt=0){
            while (q<peo_num&&dna_grp[p]==dna_grp[q])      same_cnt++,q++;
            com_r[same_cnt]++;
        }
/*
        for (int i =0 ; i< peo_num; i++){
            if (dna_grp[i].mark==1)     continue;
            int same_cnt=0;
            for ( int j =i+1; j< peo_num; j++){
                if (dna_grp[i]==dna_grp[j]&&dna_grp[j].mark==0&&dna_grp[i].mark==0){
                    same_cnt++;
                    dna_grp[j].mark=1;
                }
            }
            dna_grp[i].mark=1;
            com_r[same_cnt]++;
        }
*/
        for (int i =0 ; i<peo_num ; i++)
            cout <<com_r[i]<<endl;
    cin >>peo_num>>dna_len;
   }
    return 0;
}
