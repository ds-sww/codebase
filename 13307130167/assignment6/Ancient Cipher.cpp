#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool com(int i , int j)     {      return (i>j);    }

int main()
{
    string msg , ori_msg;
    cin >>msg >>ori_msg;
    int msg_cnt[26], ori_msg_cnt[26];
   memset(msg_cnt,0,26*sizeof(int));
    memset(ori_msg_cnt,0,26*sizeof(int));
    for (int i=0 ; i<msg.size() ; i++){
        msg_cnt[msg[i]-'A']++;
        ori_msg_cnt[ori_msg[i]-'A']++;
    }
    sort(msg_cnt,msg_cnt+26,com);
    sort(ori_msg_cnt,ori_msg_cnt+26,com);
    int i;
    for (i =0 ; i<26 ; i++){
        if (msg_cnt[i]!=ori_msg_cnt[i])     break;
    }
    if (i!=26)      cout <<"NO";
    else    cout <<"YES";
    return 0;
}
