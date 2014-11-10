#include<stdio.h>
int cow[100000];
int con[100000];
int n;
int i,j,g,h;
int find_max(int a,int b){
    int max=b-1;
    while(--b>=a){
	if(cow[b]>cow[max])
	    max=b;
        }
    return max;
}
void search(int a,int s){
    int max;
    max = find_max(a,s);
    con[max] = s-max-1;
    if(a<max)
	search(a,max);
    if(max+1<s)
	search(max+1,s);
}
int get_int(){
	char a;
	int tmp=0;
	while((a=getchar())<='9' && a>='0')
		tmp=tmp*10+a-'0';
	return tmp;
}

int main(){
	n=get_int();
    //scanf("%d",&n);
    for(i=0;i<n;i++)
		cow[i]=get_int();
//scanf("%d",&cow[i]);
    search(0,n);
    j=0;
    for(i=0;i<n;i++)
	j+=con[i];
    printf("%d\n",j);
    return 0;
}
