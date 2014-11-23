#include <iostream>
#include <algorithm>

using namespace std;

bool com(int i ,int j)      {   return (i>j);}

int main()
{
    int sce_num, item_num, div_grp_num, discount;
    cin >>sce_num;
    for (int i =0 ; i < sce_num ; i++){
        cin >>item_num;
        int *curr_sce=new int[item_num];
        div_grp_num=item_num/3;
        for (int j=0 ; j < item_num ; j++)
            cin >> curr_sce[j];
            sort(curr_sce,curr_sce+item_num,com);
        discount=0;
        for (int k=0 ; k< div_grp_num ; k++)
            discount+=curr_sce[k*3+2];
        cout << discount <<endl;
    }
    return 0;
}
