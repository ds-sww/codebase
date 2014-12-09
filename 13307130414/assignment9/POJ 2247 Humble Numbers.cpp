#include <iostream>
#include <algorithm>
using namespace std;

const long long N = 2000000000;
long long h[6000];

void humble() {
    int i = 0;
    long long num2 = 1, num3 = 1, num5 = 1, num7 = 1;
    while (num2 <= N) {
        num3 = 1;
        while (num2 * num3 <= N) {
            num5 = 1;
            while (num2 * num3 * num5 <= N) {
                num7 = 1;
                while (num2 * num3 * num5 * num7 <= N) {
                    h[i++] = num2 * num3 * num5 * num7;
                    num7 *= 7;
                }
                num5 *= 5;
            }
            num3 *= 3;
        }
        num2 *= 2;
    }
}

int main() {
    int n;
    humble();
    sort(h,h+5842);
    while (1) {
        cin >> n;
        if (n == 0) return 0;
        switch (n%10) {
            case 1 : if (n%100 != 11 && n%100 != 12 && n%100 != 13)
                        {cout << "The " << n << "st humble number is ";break;}
            case 2 : if (n%100 != 11 && n%100 != 12 && n%100 != 13)
                        {cout << "The " << n << "nd humble number is ";break;}
            case 3 : if (n%100 != 11 && n%100 != 12 && n%100 != 13)
                        {cout << "The " << n << "rd humble number is ";break;}
            default : cout << "The " << n << "th humble number is ";
        }
        cout << h[n-1] << '.' << endl;
    }
}
