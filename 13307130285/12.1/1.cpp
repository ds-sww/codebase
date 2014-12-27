#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int sum_num;
int word_num;
int number_num;
bool is_word[400];
struct Word{
  char a[200];
}word[200];
int number[200];

bool operator <(const Word&aa,const Word &bb)
{
   char x[200];
   char y[200];
   strcpy(x,aa.a);
   strcpy(y,bb.a);
   int lenx=strlen(x);
   int leny=strlen(y);
   for(int i=0;i<lenx;i++)
     if(x[i]>='A'&&x[i]<='Z')
     x[i]-='A'-'a';
   for(int i=0;i<leny;i++)
     if(y[i]>='A'&&y[i]<='Z')
     y[i]-='A'-'a';
    return strcmp(x,y)<0;

}

bool it_word(char* temp)
{
   int len=strlen(temp);
   for(int i=0;i<len-1;i++)
     if(!((temp[i]>='0'&&temp[i]<='9')||temp[i]=='-'))
      return true;
   return false;
}

void cinn(char* temp)
{
   if(it_word(temp))
   {
     is_word[sum_num]=true;
     strcpy(word[word_num].a,temp);
     word[word_num].a[strlen(temp)-1]='\0';
      sum_num++;
     word_num++;

   }
   else
   {
      is_word[sum_num]=false;
      sscanf(temp,"%d",number+number_num);
      sum_num++;
      number_num++;
   }
}

void coutt()
{
   int  x=0,y=0;
   for(int i=0;i<sum_num;i++)
   {  if(is_word[i])
      printf("%s",word[x++].a);
     else
       printf("%d",number[y++]);
     if(i==sum_num-1)
       printf(".\n");
     else
       printf(", ");
   }


}
int main()
{
   char temp[100];
   while(scanf("%s",temp)!=EOF&&temp[0]!='.')
   {
      word_num=number_num=0;
      sum_num=0;
      while(temp[strlen(temp)-1]!='.')
      {
         cinn(temp);
         scanf("%s",temp);
      }
      cinn(temp);
      sort(word,word+word_num);
      sort(number,number+number_num);
      coutt();

   }



}
