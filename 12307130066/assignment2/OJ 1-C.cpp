#include <iostream>

using namespace std;

class Xuesheng {
public:
    int xuehao;
    int yuwen;
    int shuxue;
    int yingyu;
    int zongfen;
};

int main() {
    Xuesheng xuesheng[300];
    int count;
    cin >> count;
    int i, j, k;
    Xuesheng tmp;
    for (i = 0; i < count; i++) {
        xuesheng[i].xuehao = i+1;
        cin >> xuesheng[i].yuwen;
        cin >> xuesheng[i].shuxue;
        cin >> xuesheng[i].yingyu;
        xuesheng[i].zongfen = xuesheng[i].yuwen + xuesheng[i].shuxue + xuesheng[i].yingyu;
    }
    for (i = 1; i < count; i++) {
        tmp = xuesheng[i];
        for (j = 0; j < i; j++) {
            if (xuesheng[j].zongfen > xuesheng[i].zongfen) {
                break;
            }
        }
        for (k = i; k > j; k--) {
            xuesheng[k] = xuesheng[k-1];
        }
        xuesheng[j] = tmp;
    }
    
    for (i = count - 1; i> 0; i--) {
        if (xuesheng[i].zongfen == xuesheng[i-1].zongfen) {
            if (xuesheng[i].yuwen < xuesheng[i-1].yuwen) {
                tmp = xuesheng[i-1];
                xuesheng[i-1] = xuesheng[i];
                xuesheng[i] = tmp;
            }
        }
    }
    
    for (i = count - 1; i> 0; i--) {
        if (xuesheng[i].zongfen == xuesheng[i-1].zongfen && xuesheng[i].yuwen == xuesheng[i-1].yuwen) {
            if (xuesheng[i].xuehao > xuesheng[i-1].xuehao) {
                tmp = xuesheng[i-1];
                xuesheng[i-1] = xuesheng[i];
                xuesheng[i] = tmp;
            }
        }
    }
    
    //输出部分
    for (i = 1; i <= 5; i++) {
        cout << xuesheng[count-i].xuehao  << " " << xuesheng[count-i].zongfen << endl;
    }
    return 0;
}