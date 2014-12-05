/**
 * @author whimsycwd
 * @date 2014.10.1
 */

#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<stdio.h>
#include "Matcher.h"

using namespace std;

class KMPImpl : public Matcher {
    private :
        string pattern;
        int len;
    public :
        KMPImpl(string pattern) {
            this->pattern=pattern;
            len=pattern.size();
        }

        virtual int find(string text) {
            int next[len];
            int Tlen=text.size();
            int i=2;
            int j=0;
            next[0]=-1;
            next[1]=0;
            while(i<len)
            {
                if(pattern[i-1]==pattern[j])
                {
                    next[i]=next[i-1]+1;
                    j++;
                }
                else
                {
                    next[i]=0;
                    j=0;
                }
                i++;

            }
           // for(int i=0;i<len;i++)cout<<next[i];
            i=0;
            j=0;
            while(i<=Tlen-len)
            {
                while(j!=len&&i<=Tlen&&text[i]==pattern[j])
                {
                    i++;
                    j++;
                }
                if(j==len)return i-j;
                if(j==0)
                {
                    i++;
                }
                else j=next[j];


            }

            return NOT_FOUND;
        }

        virtual ~KMPImpl() {
        }
};
/*int main()
{
    freopen("test","r",stdin);
    string a,b;
   //a="ababcd";
   //b="bcd";
   int answer;
   while(cin>>b>>a)
    {
        KMPImpl* Ka=new KMPImpl(b);
        answer=Ka->find(a);
        cout<<answer<<endl;
    }

}
*/
