#ifndef EARN_MUCH_SCHOLARSHIP_
#define EARN_MUCH_SCHOLARSHIP_
#include<iostream>
using namespace std;
class Student{
	int (*stu)[5];
	int num;
	public:
	void sort();
	void display();
	Student(int number);
	~Student(){delete  []stu;};
	void swap(int*s1,int*s2);

};
#endif
Student::Student(int number){
	int i=0;
	num=number;
	stu=new int[num][5];
	for( i=0;i<num;i++)
	{
		
		cin>>stu[i][1]>>stu[i][2]>>stu[i][3];
		stu[i][0]=i+1;
		stu[i][4]=stu[i][1]+stu[i][2]+stu[i][3];
	}
}
void Student::sort(){
	int i=0,j=1;
	for( i=0;i<num;i++)
		for(j=num-1;j>0;j--){
			if(stu[j][4]>stu[j-1][4])
				swap(stu[j-1],stu[j]);
		}
	for( i=0;i<num;i++)
		for(j=num-1;j>0;j--){
			if(stu[j][1]>stu[j-1][1]&&stu[j][4]==stu[j-1][4])
				swap(stu[j-1],stu[j]);
		}
	for(i=0;i<num;i++)
		for(j=num-1;j>0;j--){
			if(stu[j][0]<stu[j-1][0]&&stu[j][4]==stu[j-1][4]&&(stu[j][1]==stu[j-1][1]))
				swap(stu[j-1],stu[j]);
		}
}

void Student::display(){
	for(int i=0;i<num;i++)
	cout<<stu[i][0]<<" "<<stu[i][4]<<endl;
}
void Student::swap(int *s1,int *s2){
	int *temp=new int[5];
	for(int i=0;i<5;i++)
	{
		temp[i]=s1[i];
		s1[i]=s2[i];
		s2[i]=temp[i];
	}
	delete []temp;
}
int main()
{
	int num;
	cin>>num;
	Student stud(num);
	stud.sort();
	stud.display();
	getchar();getchar();
	return 0;
}
