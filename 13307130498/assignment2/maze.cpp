#include<iostream>
#include<queue>
using namespace std;

struct obj{
	char ele;
	int n, m;
	int step, key;
	obj(char e, int a, int b, int s,int k){
		ele = e;
		n = a;
		m = b;
		step = s;
		key = k;
	}
	obj(const obj &x){
		ele = x.ele;
		n = x.n;
		m = x.m;
		step = x.step;
		key = x.key;
	}
};

int main(){
	int N, M;
	cin >> N >> M;
	char **maze;
	int i, j, n, m;
	int over = 0;
	maze = new char *[N];
	for (i = 0; i < N; i++){
		maze[i] = new char[M];
	}
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			cin >> maze[i][j];
			if (maze[i][j] == 'S'){
				n = i;
				m = j;
			}
		}
	}
	int ***check;
	check = new int **[N];
	for (i = 0; i < N; i++){
		check[i] = new int *[M];
		for (j = 0; j < M; j++){
			check[i][j] = new int[2];
			check[i][j][0] = check[i][j][1] = 0;//check[i][j][0]记录拿钥匙之前是否经历过migong[i][j],check[i][j][1]记录拿到钥匙之后;
		}
	}
	queue<obj> que;
	int move[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	que.push(obj(maze[n][m], n, m, 0, 0));
	while (!que.empty() && over == 0){
		obj one(que.front());
		que.pop();
		for (i = 0; i < 4; i++){
			if (((one.n + move[i][0] >= 0) && (one.n + move[i][0] < N) && (one.m + move[i][1] >= 0) && (one.m + move[i][1] < M)) && maze[one.n + move[i][0]][one.m + move[i][1]] != '#' && (check[one.n + move[i][0]][one.m + move[i][1]][0] == 0 || check[one.n + move[i][0]][one.m + move[i][1]][1] == 0 && one.key == 1)){
				if (maze[one.n + move[i][0]][one.m + move[i][1]] == 'T'){
					over = one.step + 1;
					break;
				}
				if (one.key == 1)check[one.n + move[i][0]][one.m + move[i][1]][1] = check[one.n + move[i][0]][one.m + move[i][1]][0] = 1;
				else check[one.n + move[i][0]][one.m + move[i][1]][0] = 1;
				if (maze[one.n + move[i][0]][one.m + move[i][1]] == 'K')
					que.push(obj(maze[one.n + move[i][0]][one.m + move[i][1]], one.n + move[i][0], one.m + move[i][1], one.step + 1, 1));
				else if (maze[one.n + move[i][0]][one.m + move[i][1]] == 'D'){
					if (one.key == 1)
						que.push(obj(maze[one.n + move[i][0]][one.m + move[i][1]], one.n + move[i][0], one.m + move[i][1], one.step + 1, 0));
				}
				else que.push(obj(maze[one.n + move[i][0]][one.m + move[i][1]], one.n + move[i][0], one.m + move[i][1], one.step + 1, one.key));
			}
		}
	}
	if (over == 0)over = -1;
	cout << over << endl;
	return 0;
}
