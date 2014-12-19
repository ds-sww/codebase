#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int mod[100010];
int a[100010];

int main() {
    int c,n;
    while(1) {
        scanf("%d%d", &c, &n);
        if (c == 0 && n == 0) return 0;
        memset(mod, -1, sizeof(mod));
        long long sum = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int i;
        for (i = 0; i < n; i++) {
            sum += a[i];
            if (sum%c == 0) {
                for (int j = 1; j <= i+1; j++) {
                    printf("%d", j);
                    if (j != i+1)
                        printf(" ");
                }
                printf("\n");
                break;
            }
            else if (mod[sum%c] != -1) {
                for (int j = mod[sum%c]+1; j <= i+1; j++) {
                    printf("%d", j);
                    if (j != i+1)
                        printf(" ");
                }
                printf("\n");
                break;
            }
            else
                mod[sum%c] = i+1;
        }
        if (i == n) printf("no sweets\n");
    }
}
