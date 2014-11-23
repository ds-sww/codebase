#include <iostream>
using namespace std;

struct Stack
{
    int top;
    int * data;
    
    void Set(int n)
    {
        top = 0;
        data = new int[n + 1];
    }
    
    void Push(int t)
    {
        top++;
        data[top] = t;
    }
    
    void Pop()
    {
        top--;
    }
};

void Work()
{
    int n;
    cin >> n;

    Stack s;
    s.Set(n);

    int t;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        while(s.top > 0 && s.data[s.top] <= t)
        {
            s.Pop();
        }
        
        ans += s.top;
        s.Push(t);
    }
    
    cout << ans << endl;
    return;
}

int main()
{
    Work();
    return 0;
}
