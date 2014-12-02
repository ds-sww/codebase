#include<iostream>
#include<string>
using namespace std;

string pre,ino,ans;
char st1[30],st2[30];
int nst1,nst2;
int map[260];
int i,j,n;
char g,h;

int main(){
	while(cin >> pre >> ino){
		for(i='a';i<'z';i++)
			map[i]=-1;
		i=j=nst1=nst2;
		ans="";
		for(;i<pre.size();i++){
			st1[++nst1]=pre[i];
			map[pre[i]]=i;
			if(map[ino[j]]==-1)
				continue;
			else while(nst1>0&&ino[j]==st1[nst1]){
				++j;
				g=st1[nst1--];
				while(nst2>0&&map[st2[nst2]]>map[g]){
					ans = ans + st2[nst2--];
				}
				st2[++nst2]=g;
			}
		}
		while(nst2>0)
			ans = ans + st2[nst2--];
		cout << ans << endl;		
	}
	return 0;
}
