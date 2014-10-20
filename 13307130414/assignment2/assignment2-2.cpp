#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > fruit;
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        fruit.push(x);
    }

    int sum = 0;

    while(fruit.size() > 1)
    {
        int temp = fruit.top();
        fruit.pop();

        temp += fruit.top();
        fruit.pop();

        fruit.push(temp);
        sum += temp;
    }

    cout << sum << endl;
    return 0;
}
