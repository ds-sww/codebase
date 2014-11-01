#include <iostream>
using namespace std;
class chengji
{
    public:
    int yu,shu,ying,zong,xue;
};
int main()
{
    int n;
    chengji a[400];
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> a[i].yu >> a[i].shu >> a[i].ying;
        a[i].zong=a[i].yu+a[i].shu+a[i].ying;
        a[i].xue=i+1;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n-i-1;j++)
        {
            if (a[j].zong>a[j+1].zong)
            {
                chengji tmp;
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
            if ((a[j].zong==a[j+1].zong)&&(a[j].yu>a[j+1].yu))
            {
                chengji tmp;                                                                                                               
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
            if ((a[j].zong==a[j+1].zong)&&(a[j].yu==a[j+1].yu)&&(a[j].xue<a[j+1].xue))
            {    
                 chengji tmp;                                                                                                               
                 tmp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=tmp;
            }
        }
    }

    for (int i=0; i<5; i++)
    {
        cout << a[n-i-1].xue << ' ' << a[n-i-1].zong <<endl;
    }
}
