#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int std[n][5];
    int i,j,oi,oj;
    for(i=0;i<n;i++){
	for(j=0;j<3;j++)
	    cin>>std[i][j];
        std[i][3]=std[i][0]+std[i][1]+std[i][2];
	std[i][4]=i+1;
    }
    int order[n][5];
    for(j=0;j<5;j++)
        order[0][j]=std[0][j];

    for(i=1;i<n;i++){
	for(oi=0;oi<i;oi++){
	    if(std[i][3]>order[oi][3]){
		for(j=i;j>oi;j--)
		    for(oj=0;oj<5;oj++)
			order[j][oj]=order[j-1][oj];
		for(oj=0;oj<5;oj++)
			order[j][oj]=std[i][oj];break;}
	    if(std[i][3]==order[oi][3]){
		if(std[i][0]>order[oi][0]){
		    for(j=i;j>oi;j--)
		        for(oj=0;oj<5;oj++)
		      	    order[j][oj]=order[j-1][oj];
		    for(oj=0;oj<5;oj++)
			    order[j][oj]=std[i][oj];break;}
		if(std[i][0]<order[oi][0])
		    for(j=i;j>oi+1;j--){
		        for(oj=0;oj<5;oj++)
		      	    order[j][oj]=order[j-1][oj];
		    for(oj=0;oj<5;oj++)
			    order[j][oj]=std[i][oj];break;}
		if(std[i][0]==order[oi][0]){
    		    if(std[i][4]<order[oi][4]){
		        for(j=i;j>oi;j--)
		            for(oj=0;oj<5;oj++)
		      	        order[j][oj]=order[j-1][oj];
		        for(oj=0;oj<5;oj++)
			        order[j][oj]=std[i][oj];break;}
		    if(std[i][4]>order[oi][4])
		        for(j=i;j>oi+1;j--){
		            for(oj=0;oj<5;oj++)
		      	        order[j][oj]=order[j-1][oj];
		        for(oj=0;oj<5;oj++)
			        order[j][oj]=std[i][oj];break;}
		}
	    }
	}
	if(oi==i)
	    for(oj=0;oj<5;oj++)
		order[i][oj]=std[i][oj];
    }
    for(i=0;i<5;i++)
	cout<<order[i][4]<<"  "<<order[i][3]<<endl;

    return 0;
}

