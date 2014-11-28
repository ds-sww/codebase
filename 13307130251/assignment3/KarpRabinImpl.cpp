/**
 * @author whimsycwd
 * @date   2014.10.1
 */
#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>

#include "Matcher.h"

using namespace std;

class KarpRabinImpl : public Matcher
{

private :

    string pattern;
    int mod=12345678;

public :

    explicit KarpRabinImpl(const string & pattern)
    {
        this->pattern=pattern;

    }

    virtual int find(string text)
    {
        int Plen=pattern.size();
        int Tlen=text.size();
        long long Phash,Thash,d;
        Phash=0;
        Thash=0;
        d=1;
        for(int i=0; i<Plen; i++)
        {
            d=d<<1;
            if(d>mod)d=d%mod;
            Phash=((Phash<<1)+pattern[i]);
            if(Phash>d)Phash=Phash%mod;
            Thash=((Thash<<1)+text[i]);
            if(Thash>d)Thash=Thash%mod;
        }
        d=d/2;
        //cout<<Phash<<endl;
        //cout<<d<<endl;
        for(int j=0; j<Tlen-Plen+1; j++)
        {
            if(Thash==Phash&&memcmp(&text[j],&pattern[0],Plen)==0)
            //if(Thash==Phash)
                return j;
            else
            {
                Thash=(( (Thash-text[j]*d)<<1)+text[j+Plen])%mod;
                while(Thash<0)Thash+=mod;
            }
        }
        return NOT_FOUND;
    }

    virtual ~KarpRabinImpl()
    {
    }
};
/*int main()
{
   //freopen("test","r",stdin);
    string a,b;
  //  a="bhahbaeegehghcbedjbchijdjaaeegbhgbejdafjfchchigahaegiejhgadaiejefggagbjbghgfhehhebdchfbdhfdfjdchjajhz";
    //b="hahbaeegehghcbedjbchijdjaaeegbhgbejdafjfchchigahaegiejhgadaiejefggagbjbghgfhehhebdchfbdhfdfjdchjajhz";
    while(cin>>b>>a)
{
        KarpRabinImpl* Ka=new KarpRabinImpl(b);
        cout<<Ka->find(a)<<endl;


}
}
*/
