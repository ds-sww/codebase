#include <vector>  
#include <deque> 
#include <iostream>
using namespace std;  
  
vector<int> maxInWindow(const vector<int>& num,int size){  
    vector<int> maxInWindow;  
    if (int(num.size())>=size&&size>=1)  
    {  
        deque<int> index;  
        for (int i = 0; i < size; i++)  
        {  
            while (!index.empty()&&num[i]>=num[index.back()])  
            {  
                index.pop_back();  
            }  
  
            index.push_back(i);  
        }  
  
        for (int i = size; i < int(num.size()); i++)  
        {  
            maxInWindow.push_back(num[index.front()]);  
  
            while (!index.empty()&&num[i]>=num[index.back()])  
            {  
                index.pop_back();  
            }  
            if (!index.empty()&&index.front()<=(i-size))  
            {  
                index.pop_front();  
           }  
            index.push_back(i);  
        }  
       maxInWindow.push_back(num[index.front()]);  
    }  
  
    return maxInWindow;  
}  
vector<int> minInWindow(const vector<int>& num,int size){  
    vector<int> minInWindow;  
    if (int(num.size())>=size&&size>=1)  
    {  
        deque<int> index;  
        for (int i = 0; i < size; i++)  
        {  
            while (!index.empty()&&num[i]<=num[index.back()])  
            {  
                index.pop_back();  
            }  
  
            index.push_back(i);  
        }  
  
        for (int i = size; i < (int )num.size(); i++)  
        {  
            minInWindow.push_back(num[index.front()]);  
  
            while (!index.empty()&&num[i]<=num[index.back()])  
            {  
                index.pop_back();  
            }  
            if (!index.empty()&&index.front()<=(i-size))  
            {  
                index.pop_front();  
           }  
            index.push_back(i);  
        }  
       minInWindow.push_back(num[index.front()]);  
    }  
  
    return minInWindow;  
}  



int main(){
	vector <int> num,max,min;
	int length, size,i,h;
	cin>>length;
	cin>>size;
	for(int j=0;j<length;j++){
		cin>>i;
		num.push_back(i);
	}
	max=maxInWindow(num,size);
	min=minInWindow(num,size);
	h=length-size+1;
	for(int i=0;i<h;i++)
	{
		cout<<min[i]<<" ";
	}cout<<endl;
	for(int i=0;i<h;i++)
	{
		cout<<max[i]<<" ";
	}cout<<endl;
	return 0;
}