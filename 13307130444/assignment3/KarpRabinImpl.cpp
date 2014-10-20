#include<iostream> 
#include<string> 

 
#include "Matcher.h" 
 
using namespace std; 
#define Rehash(a,b,h) ((((h)-(a)*d)<<1)+(b))

class KarpRabinImpl:public Matcher { 
     
    private :
		string pattern; 
public : 
         explicit KarpRabinImpl( string & pattern) {
			 this->pattern=pattern;
         }  
          
         virtual int find(string text);
         virtual ~KarpRabinImpl() {pattern.~string(); } 
 }; 
int KarpRabinImpl::find(string text){
	int d,n=text.length(),m=pattern.length(),i,j,ht,hp;
	for(d=i=1;i<m;i++)d=d<<1;
	for(ht=hp=i=0;i<m;i++){
		ht=(ht<<1)+text[i];
		hp=(hp<<1)+pattern[i];
	}
	for(j=0;j<=n-m;j++){
		//若哈希值相等判断字符串类是否相同
		if(ht==hp&&!text.compare(j,m,pattern,0,m))
		return j;
		ht=Rehash(text[j],text[j+m],ht);
	}
	return NOT_FOUND;
}