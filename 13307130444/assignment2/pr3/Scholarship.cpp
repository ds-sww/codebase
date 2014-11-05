#include" Scholarship.cpp"
Stu::Stu(int number)
{
	num=number;
	assert (6<=num<=300); 
	stu=new int[num][5];
	for( int i=0;i<num;i++)
	{cin>>stu[i][1]>>stu[i][2]>>stu[i][3];
		stu[i][0]=i+1;
		stu[i][4]=stu[i][1]+stu[i][2]+stu[i][3];
	}
}
void Stu::sort()
{
	for(int i=0;i<num;i++)
		fot(int j=1;j<num;j++)
		{
			if(stu[j][4]>stu[i][4])
				swap(stu[i],stu[j]);
		}
	for(int i=0;i<6;i++)
		for(int j=1;j<6;j++)
		{
			if(stu[j][0]<stu[i][0])
				swap(stu[i],stu[j]);
		}
}

void Stu::display()
{
	for(int i=0;i<6;i++)
	cout<<stu[i][0]<<" "<<stu[i][4]<<endl;
}
void Stu::swap(int *s1,int *s2)
{
	int *temp=new int[5];
	for(int i=0;i<6;i++)
	{
		temp[i]=s1[i];
		s1[i]=s2[i];
		s2[i]=temp[i];
	}
}



