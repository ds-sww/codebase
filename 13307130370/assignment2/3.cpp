#include<iostream>
using namespace std;
struct student{
	int num;
	int chinese;
	int english;
	int math;
	int sum;
};
int main()
{
	student a[300];
	int i,p;
	cin>>i;
	for(int j=0;j<i;j++)
	{
		a[j].num=j+1;
		cin>>a[j].chinese>>a[j].english>>a[j].math;
		a[j].sum=a[j].chinese+a[j].math+a[j].english;
	}
	student temp;
	for(int j=0;j<5;j++)
	{
		temp=a[0];
		for(int q=0;q<i;q++)
		{
			if(a[q].sum>temp.sum)
			{
				temp=a[q];
				p=q;
			}
			else if(a[q].sum==temp.sum)
			{
				if(a[q].chinese>temp.chinese)
				{
					temp=a[q];
					p=q;
				}
				else if(a[q].chinese==temp.chinese)
				{
					if(a[q].num<temp.num)
					{
						temp=a[q];
						p=q;
					}
				}
			}
		}
		cout<<temp.num<<" "<<temp.sum<<endl;
		a[p].sum=0;
	}
}

