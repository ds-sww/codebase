#include <iostream>
#include <string>
using namespace std;

string a, b;

int main()
{
    while(!cin.eof())
    {
        cin >> a;
        if(cin.eof()) return 0;
        cin >> b;
        int cnt = 0;
        for(int i = 0; i <= (int)a.length() - (int)b.length(); i++)
        {
            if(a.substr(i, b.length()) == b)
            {
                cnt++;
                if(cnt == 1)cout << i;
                else cout << ' ' << i;
            }
        }
        if(cnt)
        {
            cout << endl;
        }
        else cout << -1 << endl;
    }
}