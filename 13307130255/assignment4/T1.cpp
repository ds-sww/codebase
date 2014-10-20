
#include <stdio.h>
#include <stack>

using namespace std;
stack<int> station;
int p[1010];
void station_empty()
{
    while(!station.empty()) station.pop();
}
int main(int argc, char **argv)
{
	int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int i ,t;
        bool success;
        while(true)
        {
            scanf("%d",&p[0]);
            if(p[0] == 0 ) break;
            for(i = 1;i<n;i++) scanf("%d",&p[i]);
            t = 0; success = true;
            for(i = 0;i<n;i++)
            {
                if(p[i] < t)
                {
                    if(p[i] != station.top()) 
                    {
                        success = false;
                        break;
                    }
                    station.pop();
                }else
                {
                    while(t!=p[i]) station.push(++t);
                    station.pop();
                }
            }
            if(success) printf("Yes\n"); else printf("No\n");
            station_empty();
            
        }
        printf("\n");
        scanf("%d",&n);
        
    }
	return 0;
}

