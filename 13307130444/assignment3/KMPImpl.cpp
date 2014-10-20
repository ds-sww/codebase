#include<string> 
#include<vector> 
#include<iostream>

#include "Matcher.h" 
#define SIZE 200
using namespace std; 

class KMPImpl : public Matcher {
private :  
        string pattern; 
		int Next[SIZE];
public : 
     explicit KMPImpl(const string pattern){ this->pattern=pattern; } 
	 virtual int find(string text); 
	 virtual ~KMPImpl() {pattern.~string();}
	 void preprocessing();
		}; 
void KMPImpl::preprocessing(){
	int m=pattern.length();
	for( int i=0,j=Next[0]=-1;i<m;){//m-1
	for(;j>-1&&pattern[i]!=pattern[j];)
		j=Next[j];
		i++;j++;
			Next[i]=j;
	}
	}


int KMPImpl:: find(string text){
	int i,j,m=pattern.length(),n=text.length();
	preprocessing();
	for(i=j=0;j<n;){
		for(;i>-1&&pattern[i]!=text[j];)i=Next[i];
		i++;j++;
		if(i>=m)return j-i;
	}return  NOT_FOUND;
}

