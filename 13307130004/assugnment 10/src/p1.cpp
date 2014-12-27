#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 500

using namespace std;

int counter,word_counter,number_counter;
bool judge[N];
struct Word{
  char w[N];
}words[N];
int number[N];

bool operator <(const Word &w1,const Word &w2){
   char x1[N],x2[N];
   strcpy(x1,w1.w);
   strcpy(x2,w2.w);
   int l1=strlen(x1),l2=strlen(x2);
   for(int i=0;i<l1;i++)
    	if(x1[i]>='A'&&x1[i]<='Z')
     		x1[i]-='A'-'a';
   for(int i=0;i<l2;i++)
     	if(x2[i]>='A'&&x2[i]<='Z')
     		x2[i]-='A'-'a';
    if (strcmp(x1,x2)<0)
    	return true;
    else 
    	return false;
}

void get(char* temp){
	bool j;
	int len=strlen(temp);
    if((temp[0]>='0'&&temp[0]<='9')||temp[0]=='-')
   		j=true;
   	else
   		j=false;
   if(!j){
    	judge[counter]=true;
   		strcpy(words[word_counter].w,temp);
    	words[word_counter].w[len-1]='\0';
    	counter++;
    	word_counter++;
   }
   	else{
    	judge[counter]=false;
    	bool sy=true;
    	int i=0;
        if(temp[0]=='-'){
    	  	sy=false;
    	  	i++;
    	}
    	number[number_counter]=0;
        for(;i<len-1;i++)
      		number[number_counter]=number[number_counter]*10+temp[i]-'0';
        if(!sy)
      		number[number_counter]=-number[number_counter];
      	counter++;
      	number_counter++;
   	}
}
int main(){
	int w_counter,n_counter;
   	char temp[N];
   	while(scanf("%s",temp)!=EOF&&temp[0]!='.'){
      	word_counter=number_counter=counter=0;
      	get(temp);
      	while(temp[strlen(temp)-1]!='.')
      	{
      	  scanf("%s",temp);
      	  get(temp);
      	}
      	sort(words,words+word_counter);
      	sort(number,number+number_counter);
      	w_counter=0,n_counter=0;
   		for(int i=0;i<counter;i++){
			if(judge[i])
      			printf("%s",words[w_counter++].w);
     		else
       			printf("%d",number[n_counter++]);
     		if((i+1)==counter)
       			printf(".\n");
       		else
       			printf(", ");
   		}	
   	}
   	return 0;
}