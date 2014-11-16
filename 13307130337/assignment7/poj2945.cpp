#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int GetGeneVal(char c)
{
    if (c == 'A') return 1;
    if (c == 'G') return 2;
    if (c == 'C') return 3;
    if (c == 'T') return 4;
};

struct Tree
{
    int ch[5];
    int num;
    int end;
    void Set()
    {
        end = 0;
        num = 0;
        memset(ch, 0, sizeof(ch));
    }
} trie[400050];
int trieCnt = 0;

int seq[20050];
int seqCnt = 0;

int ans[20050];
int n;
int m;

void InsertGene(char s[])
{
    int gene = 0;
    int cur = 0;
    int exist = 1;

    for (int i = 0; i < m; i++)
    {
        gene = GetGeneVal(s[i]);
        if(trie[cur].ch[gene] == 0)
        {
            exist = 0;
            trieCnt++;
            trie[trieCnt].Set();
            trie[cur].ch[gene] = trieCnt;
            cur = trieCnt;
        }
        else
        {
            cur = trie[cur].ch[gene];
        }
    }

    if (exist == 1)
    {
        seq[trie[cur].end]++;
    }
    else
    {
        seqCnt++;
        seq[seqCnt] = 1;
        trie[cur].end = seqCnt;
    }
    return;
}

void Init()
{
    trieCnt = 0;
    for(int i = 0; i <= n * m; i++)
    {
        trie[i].Set();
    }

    seqCnt = 0;
    memset(seq, 0, sizeof(seq));

    memset(ans, 0, sizeof(ans));
}

int main()
{
    char s[50];
    while (1)
    {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) return 0;

        Init();
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", s);
            InsertGene(s);
        }

        for(int i = 1; i <= seqCnt; i++)
        {
            ans[seq[i]]++;
        }

        for(int i = 1; i <= n; i++)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
