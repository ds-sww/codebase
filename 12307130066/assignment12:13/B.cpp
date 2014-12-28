#include<cstdio>
using namespace std;
struct Animal {
        int parent;
        int relation;
};
Animal animal[50010];

int getRoot(int x) {
        if(x!=animal[x].parent)
        {
                int fx=getRoot(animal[x].parent);
                animal[x].relation=(animal[x].relation+animal[animal[x].parent].relation)%3;
                animal[x].parent=fx;
        }
        return animal[x].parent;
}

bool merge(int X, int Y, int Type) {
        int rX = getRoot(X);
        int rY = getRoot(Y);
        if(rX == rY && Type != (animal[Y].relation - animal[X].relation + 3) % 3) {
                return false;
        }
        if(rX == rY) {
                return true;
        }
        animal[rY].parent = rX;
        animal[rY].relation = (animal[X].relation - animal[Y].relation + Type + 3) % 3;
        return true;
}

int main() {
        int N, K;
        scanf("%d%d", &N, &K);
        for(int i = 1; i <= N; i++) {
                animal[i].parent = i;
                animal[i].relation = 0;
        }
        int tmp1, tmp2, tmp3, count = 0;
        for(int i = 0; i < K; i++) {
                scanf("%d%d%d", &tmp1, &tmp2, &tmp3);
                if(tmp2 > N || tmp3 > N || (tmp2 == tmp3 && tmp1 == 2)) {
                        count++;
                }
                else {
                        if(!merge(tmp2, tmp3, tmp1 - 1)) {
                                count++;
                        }
                }
        }
        printf("%d\n", count);
        return 0;
}