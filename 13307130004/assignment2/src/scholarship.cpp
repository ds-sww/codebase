#include <iostream>
#define N 305
#define M 5
using namespace std;

class Student{
private:
	int number,chinese,maths,english,total;
public:
	void build(int num,int chi, int mat, int eng){
		number=num;
		chinese=chi;
		maths=mat;
		english=eng;
		total=chi+mat+eng;
	};
	bool operator > (Student sdu){
		if(total>sdu.total)
			return true;
		else if(total==sdu.total)
		{
			if(chinese>sdu.chinese)
				return true;
			else if(chinese==sdu.chinese)
			{

				if(number<sdu.number)
					return true;
				else
					return false;

			}
		}
		return false;
	};
	void print()
	{
		cout<<number<<" "<<total<<endl;
	};
};
int main(){
	int n,i,j,chi,mat,eng;
	Student sdu[N];
	Student temp;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>chi>>mat>>eng;
		sdu[i-1].build(i,chi,mat,eng);
	}
	for (i=0;i<M;i++)
	{
		for (j=n-1;j>i;j--)
		{
			if(sdu[j]>sdu[j-1])
			{
				temp=sdu[j-1];
				sdu[j-1]=sdu[j];
				sdu[j]=temp;
			}
		}
	}
	for(i=0;i<M;i++)
		sdu[i].print();
	return 0;
}
