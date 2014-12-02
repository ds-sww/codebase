#include "cmath"
#include "cstdlib"
#include "climits"
#include "vector"
#include "queue"
#include "map"
#include "set"
#include "string"
#include "cstring"
#include "cstdio"
#include "iostream"
#include "algorithm"
using namespace std;



const int INF = 1000000000;
typedef int arr[1100000];

arr q, a, s;
int h, t, n, k;

int main()
{
      scanf("%d %d", &n, &k);
      for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

      q[0] = -INF;
      q[1] = a[1];
      s[1] = 1;
      h = t = 1;

      for (int i = 2; i <= k; i++) {      
            while (a[i] < q[t] && h <= t) --t;
            q[++t] = a[i];
            s[t] = i;
      }

      printf("%d ",q[h]);
      for (int i = 1; i <= n - k; i++)
      {
            while (s[h] <= i && h <= t) ++h;
            while (a[i + k] < q[t] && h<=t) --t;
            q[++t] = a[i + k];
            s[t] = i + k;
            printf("%d ", q[h]);
      }

      printf("\n");

      q[0] = INF;
      q[1] = a[1];
      s[1] = 1;
      h = t = 1;

      for (int i = 2; i <= k; i++)
      {
            while (a[i] > q[t] && h <= t) --t;
            q[++t] = a[i];
            s[t] = i;
      }

      printf("%d ",q[h]);
      for (int i = 1; i <= n - k; i++)
      {
            while (s[h] <= i && h <= t) ++h;
            while (a[i + k] > q[t] && h <= t) --t;
            q[++t] = a[i + k];
            s[t] = i + k;
            printf("%d ", q[h]);
      }
}
