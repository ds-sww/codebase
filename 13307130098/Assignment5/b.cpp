#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>

char c[1000000];
int l, now;

int getint()
{
    int res = 0;
    while(c[now] >= '0' && c[now] <= '9')
    {
        res *= 10;
        res += c[now] - '0';
        now++;
    }
    return res;
}

int getstep(char c)
{
    if(c == 0 || c == ')') return 0x80808080;
    if(c == '+' || c == '-') return 0;
    if(c == '*' || c == '/') return 1;
    if(c == '^')return 2;
    assert(0);
}

int calc(int x, char s, int y)
{
    if(s == '+') return x+y;
    if(s == '-') return x-y;
    if(s == '*') return x*y;
    if(s == '/') return x/y;
    if(s == '^') return pow(x, y);
}
int dfs(int x, char s)
{
    int y;
    while(1)
    {
        if(c[now] == '(')
        {
            now++;
            y = dfs(0, '+');
            now++;
        }
        else y = getint();
        while(1)
        {
            char nexts = c[now++];
            if(getstep(nexts) < getstep(s))
            {
                now--;
                return calc(x, s, y);
            }
            else if(getstep(nexts) > getstep(s) || (s == nexts && s == '^'))
            {    
                y = dfs(y, nexts);
            }
            else 
            {
                x = calc(x, s, y);
                s = nexts;
                break;
            }
        }
    }
}
int main()
{
    while(scanf("%s", c) != EOF)
    {
        l = strlen(c);
        now = 0;
        printf("%d\n", dfs(0, '+'));
        memset(c, 0, sizeof(c));
    }
}