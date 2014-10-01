/**
 *  @author forward
 *  @date   2014.9.29
 *
 */

#include "cstdio"
#include "iostream"
#include "queue"

using namespace std;


class heap{
    public:
    int size;
    int h[100000];
    
    heap()
    {
        size = 0;
    }
    
    void swap(int a, int b)
    {
        int temp = h[a];
        h[a] = h[b];
        h[b] = temp;
    }
    
    void up(int k)
    {
        while (k > 1 && h[k] < h[k>>1]) swap(k,k>>1), k >>= 1;
    }
    
    void dn(int k)
    {
        while (k <= size >> 1)
        {
            int p = k<<1;
            if (p < size && h[p+1] < h[p]) p++;
            if (h[p] < h[k]) swap(k, p), k = p;
            else break;
        }
    }
    
    void ins(int k)
    {
        h[++size] = k; up(size);
    }
    
    void del()
    {
        swap(1,size--); dn(1);
    }
    
}h;

int n;

int main(int argc, char const *argv[])
{
    //freopen("2.txt", "r", stdin);

    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin>>tmp;
        h.ins(tmp);
    }
    int ans = 0;
    int min1, min2;
    while (h.size > 1) {
        min1 = h.h[1]; h.del();
        min2 = h.h[1]; h.del();

        ans += (min1 + min2);
        h.ins(min1 + min2);
    }

    cout<<ans<<endl;


    return 0;
}