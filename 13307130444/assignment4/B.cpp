#include<stack>
#include<vector>
#include<queue>
#include <iostream>
using namespace std;

class Element {  
public: int height; // 每一个柱状条的高度（宽度为1）  
		int index; // 每个柱状条的x坐标值，代表它们出现的相对次序  
        Element(int height, int index) {  
        this->height = height;  
        this->index = index;  
    }  
} ; 

int maxRectangleValue(int num) {  
		int m=num,*array=new int[num];
		vector<Element> input;  
		for(int i=0;i<m;i++){
			cin>>array[i];
			Element element(array[i],i);
			input.push_back(element);
		}
		int maxValue = 0; 
		stack<Element> stk;  
        for (int i=0;i<m;i++) {  
            if (stk.empty())  
                stk.push(input[i]);  
            else {  
                while (input[i].height < stk.top().height) { // 出栈，并计算最大矩形大小  
                    Element topElement = stk.top();  
					stk.pop();
                    int tmpValue = topElement.height * (input[i].index - topElement.index); // height * width  
                    if (tmpValue > maxValue)  
                        maxValue = tmpValue;  
                    if (stk.empty())  
                        break;  
				}  
                // 进栈  
                stk.push(input[i]);
			}  
        }  
		    while (!stk.empty()) { 
			Element topElement =stk.top(); 
			stk.pop();  
            int tmpValue = topElement.height * ((m - 1) - topElement.index + 1); // height * width  
            if (tmpValue > maxValue)  
                maxValue = tmpValue;  
        }  
        return maxValue;  
    }  
      
int main()
{
	int i;
	queue<int> q;
	while(cin>>i,i!=0)
	{
		q.push(maxRectangleValue(i));
	}
	while(!q.empty()){
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;getchar();getchar();
}

