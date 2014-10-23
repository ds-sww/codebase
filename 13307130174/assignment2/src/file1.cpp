#include<iostream>

using namespace std;

struct student
{
    int no,lan,math,eng,total;
}stu[300],temp;


int main()
{
    int n,i,j;
    cin>>n;
    for (i=0;i<n;i++)
    {
        stu[i].no=i;
        cin>>stu[i].lan>>stu[i].math>>stu[i].eng;
        stu[i].total=stu[i].lan+stu[i].math+stu[i].eng;
    }
    for (i=0;i<n-1;i++)
        for (j=0;j<n;j++)
        {
            if (stu[i].total>stu[j].total || (stu[i].total==stu[j].total && stu[i].lan>stu[j].lan) || (stu[i].total==stu[j].total && stu[i].lan==stu[j].lan && stu[i].no<stu[j].no))
            {
                temp=stu[i];
                stu[i]=stu[j];
                stu[j]=temp;
            }
        }
    for (i=0;i<5;i++) cout<<stu[i].no+1<<" "<<stu[i].total<<endl;
    return 0;
}