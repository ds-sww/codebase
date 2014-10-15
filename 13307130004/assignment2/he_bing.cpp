#include <iostream>
#define N 10100
using namespace std;

class heap{
private:
	int n;
	int a[N];
	long int total;
	int compare(int i){
		if(2*i==n)
		{
			if (a[i]<=a[2*i])
				return i;
			else
				return n;
		}
		else
		{
			if(a[i]<=a[2*i])
			{
				if (a[i]<=a[2*i+1])
					return i;
				else
					return (2*i+1);
			}
			else
			{
				if (a[2*i]<=a[2*i+1])
					return (2*i);
				else
					return (2*i+1);
			}
		}
	return i;
	};
public:
	heap(){
		n=0;total=0;
	};
	void rise (int ele){
		int i,temp;
		n++;
		a[n]=ele;
		i=n;
		while(i!=1&&a[i/2]>a[i]){
			temp=a[i/2];
			a[i/2]=a[i];
			a[i]=temp;
			i=i/2;
		};
	};
	void sink (){
		int i=1,temp,tempi;
		a[1]=a[n];
		n--;
		while((2*i)<=n&&i!=compare(i)){
			tempi=compare(i);
			temp=a[tempi];
			a[tempi]=a[i];
			a[i]=temp;
			i=tempi;
		};
	};
	long int he_bing(){
		while(n!=1){
			int temp;
			temp=a[1];
			sink();
			temp+=a[1];
			sink();
			total+=temp;
			rise(temp);
		};
		return total;
	};
};
int main(){
	int n,temp;
	heap guozi;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		guozi.rise(temp);

	}
	cout<<(guozi.he_bing())<<endl;
	return 0;
}
