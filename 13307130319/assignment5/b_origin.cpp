#include <cstdio>
#include <cstring>

char str[100000];

int power(int x, int n)
{
	int s=1;
	while (n)
	{
		if (n&1) s*=x;
		x*=x;
		n>>=1;
	}
	return s;
}

int calc(int l, int r)
{
	while (str[l]=='(' && str[r]==')') ++l, --r;
	int cnt=0;
	for (int i=r; i>=l; --i)
	{
		if (str[i]=='(') --cnt;
		if (str[i]==')') ++cnt;
		if (str[i]=='+' && !cnt) return calc(l, i-1)+calc(i+1, r);
		if (str[i]=='-' && !cnt) return calc(l, i-1)-calc(i+1, r);
	}
	for (int i=r; i>=l; --i)
	{
		if (str[i]=='(') --cnt;
		if (str[i]==')') ++cnt;
		if (str[i]=='*' && !cnt) return calc(l, i-1)*calc(i+1, r);
		if (str[i]=='/' && !cnt) return calc(l, i-1)/calc(i+1, r);
	}
	for (int i=l; i<=r; ++i)
	{
		if (str[i]=='(') --cnt;
		if (str[i]==')') ++cnt;
		if (str[i]=='^' && !cnt) return power(calc(l, i-1), calc(i+1, r));
	}
	int x=0;
	for (int i=l; i<=r; ++i) x=x*10+str[i]-'0';
	return x;
}

int main()
{
	while (scanf("%s", str)!=EOF)
		printf("%d\n", calc(0, strlen(str)-1));
	return 0;
}

