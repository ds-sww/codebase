/**
 * @author whimsycwd
 * @date   2014.10.2
 * bad character shift 和 good suffix shift 都是偏移的必要条件
 */

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#include "Matcher.h"
#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;
const int ASIZE=100;
const int XSIZE=100;

class BoyerMooreImpl : public Matcher {
private :
        string pattern;
		int bmBc[ASIZE];
		int bmGs[XSIZE];
public :

        BoyerMooreImpl(string pattern) {this->pattern=pattern;}
		int find(string text);
		void preBmBc(int bmBc[]);
		void preBmGs(int bmGs[]);
		void suffixes(int* suff);
        virtual ~BoyerMooreImpl() {}
};
void BoyerMooreImpl::preBmBc(int bmBc[])
{
	int i,m=pattern.length();
		for(i=0;i<ASIZE;++i)
		bmBc[i]=m;
	for(i=0;i<m-1;++i)
		bmBc[pattern[i]]=m-1-i;
}
void BoyerMooreImpl::suffixes(int *suff)
{
	int f,g,l,m=pattern.length();//f为匹配区间右端标号
	suff[m-1]=m;//g为匹配区间左端标号
	g=m-1;
	for(l=m-2;l>=0;--l){
		if(l>g&&suff[l+m-1-f]<l-g)
			suff[l]=suff[l+m-1-f];
		else{
			if(l<g)
				g=l;
			f=l;
			while(g>=0&&pattern[g]==pattern[g+m-1-f])
				--g;
			suff[l]=f-g;
		}
	}
	

}
void BoyerMooreImpl::preBmGs(int bmGs[])
{
	int i,j=0,suff[XSIZE],m=pattern.length();
	suffixes(suff);
		for(i=0;i<m;++i)
		bmGs[i]=m;
	for(i=m-1;i>=-1;--i)
	if(i==-1||suff[i]==i+1)
		for(j=0;j<m-1-i;++j)
			{if(bmGs[j]==m)
			bmGs[j]=m-1-i;}
	for(i=0;i<m-1;++i)
	{bmGs[m-1-suff[i]]=m-1-i;}
}

int BoyerMooreImpl::find(string text)
{
	int i,j,m=pattern.length(),n=text.length(),bmGs[XSIZE],bmBc[ASIZE];

	//preBmBc
	preBmBc(bmBc);
	//preBmGs
	//就算辅助数组suff[]
	//preBmGs	
	preBmGs(bmGs);
	//查找
	j=0;
	while(j<n-m){///是否匹配到尽头
		for(i=m-1;i>=0&&pattern[i]==text[i+j];--i);
			{if(i<0)
				return j;
			else
				j+=Max(bmGs[i],bmBc[text[i+j]]-m+1+i);}
	}
}








