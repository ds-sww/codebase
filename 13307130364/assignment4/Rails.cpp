#include<iostream>
#include <stack> 
#include<string>
using namespace std;
string t="";
void func(const int* a,const int count){
	stack<int> p;
	int j = 1;
	int i = 0;
	int flag = 0;
	for (; i < count;){
		if (a[i] > j)
			p.push(j++);
		else if(a[i]==j){
			j++;
			i++;
		}
		else{
			if (a[i] == p.top()){
				i++;
				p.pop();
			}
			else{
				flag = 0;
				break;
			}
		}
		if (j == count + 1 && i == count){
			t+= "\nYes";
			flag = 1;
			break;
		}
	}
	if (!flag)
		t += "\nNo";

}
int main(){
	int count,temp,flag=1;
	cin >> count;
	for (; count;cin>>count){
		int *a = new int[count];
		//cout << endl;//Blank line?
		while (1){
			cin >> temp;
			if (temp == 0){
				t += "\n";
				break;
			}
			else{
				a[0] = temp;
				for (int i = 1; i < count; i++)
					cin >> a[i];
				func(a,count);
			}
		}
	}
	cout << t.substr(1,t.length()-2);
	return 0;
}
