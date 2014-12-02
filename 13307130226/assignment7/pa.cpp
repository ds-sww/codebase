#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m;
vector<int> fri;
bool cmp(int a,int b){
    return a>b;
}
int tn;
int i,j;
int main(){
    cin >> t;
    tn=1;
    while(t--){
	cin >> n >> m;
	fri.resize(m);
	for(i=0;i<m;i++)
	    cin >> fri[i];
	sort(fri.begin(),fri.end(),cmp);
	cout << "Scenario #" << tn++ <<':'<< endl;
	for(i=0;i<m;i++){
	    n-=fri[i];
	    if(n<=0)
		break;
	}
	if(i==m)
	    cout << "impossible" << endl << endl;
	else
	    cout << i+1 <<  endl << endl;
    }
    return 0;

}
