#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str[100];
int num[100];
string cha[100];
bool flag[100];
string word[100];
int inum,ichar,iflag;

bool cmp(string a, string b) {
    char c[30];
    char d[30];
    for (int i = 0; i < a.length(); i++)
        c[i] = isupper(a[i]) ? a[i] - 'A' + 'a' : a[i];
    for (int i = 0; i < b.length(); i++)
        d[i] = isupper(b[i]) ? b[i] - 'A' + 'a' : b[i];
    return strcmp(c,d) < 0;
}

bool input() {
    iflag = 0;
    cin >> str;
    if (str[0] == '.') return true;
    while (str[strlen(str)-1] != '.') {
        str[strlen(str)-1] = '\0';
        word[iflag] = str;
        if (isalpha(str[0]))
            flag[iflag++] = true;
        else
            flag[iflag++] = false;
        cin >> str;
    }
    str[strlen(str)-1] = '\0';
    word[iflag] = str;
    if (isalpha(str[0]))
        flag[iflag++] = true;
    else
        flag[iflag++] = false;
    return false;
}

void par() {
    inum = ichar = 0;
    for (int i = 0; i < iflag; i++) {
        if (flag[i])
            cha[ichar++] = word[i];
        else {
            if (word[i][0] != '-') {
                for (int j = 0; j < word[i].length(); j++)
                    num[inum] = num[inum]*10 + word[i][j] - '0';
            }
            else {
                for (int j = 1; j < word[i].length(); j++)
                    num[inum] = num[inum]*10 + word[i][j] - '0';
                num[inum] = (-1) * num[inum];
            }
            inum++;
        }
    }
    return;
}

int main() {
    while (1) {
        if (input()) return 0;
        par();
        sort(num, num+inum);
        sort(cha, cha+ichar, cmp);
        int in = 0, ic = 0;
        if (flag[0])
            cout << cha[ic++];
        else
            cout << num[in++];
        for (int i = 1; i < iflag; i++) {
            if (flag[i])
                cout << ", " << cha[ic++];
            else
                cout << ", " << num[in++];
        }
        cout << '.' << endl;
        memset(num, 0, sizeof(num));
    }
}
