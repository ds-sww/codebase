#include<cstdio>
#include<iostream>
using namespace std;

int train[1010],request[1010],trains;
int main(){
	int n;
	bool first = true;
	while(1){
		//cout << 'h';
		cin >> n;
		if(n == 0)
			return 0;
		
		if(!first)
			cout  <<endl;
		first = false;
		for(int i=0;i<n;i++){
			scanf("%d",&request[i]);
		}
		do{
		trains = 0;int now = 1;
		bool able = true;
		for(int i=0;i<n;i++){
			while(now != request[i] && train[trains-1] != request[i] && now<n)
				train[trains++]=now++;
			if(now == request[i])
				continue;
			if(train[trains-1] == request[i])
				trains--;
			else{
				able = false;
				break;
			}
			
		}
		if(able)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		int tmp;
		cin >> tmp;
		if(tmp == 0){break;}
		else{
			request[0] = tmp;
			for(int i=1;i<n;i++){
				scanf("%d",&request[i]);
			}
		}
		}while(1);
	}
return 0;
}
