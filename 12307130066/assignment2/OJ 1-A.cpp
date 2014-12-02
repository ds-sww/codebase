#include <iostream>
#include <queue>

using namespace std;

struct State {
	int x, y;
	int step, key;
	State(int a, int b, int c, int d) {
		x = a;
		y = b;
		step = c;
		key = d;
	}
};

int main() {
	char Maze[20][20];
	int visited[20][20][2];
	//初始化上述两个矩阵
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			Maze[i][j] = '#';
			visited[i][j][0] = 0;
			visited[i][j][1] = 0;
		}
	}
	int rows, cols;
	cin >> rows >> cols;
	//输入迷宫
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			cin >> Maze[i][j];
		}
	}
	//查找起始点与终点
	int sx, sy, tx, ty;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(Maze[i][j] == 'S') {
				sx = i;
				sy = j;
				Maze[i][j] = '*';
			}
			else if(Maze[i][j] == 'T') {
				tx = i;
				ty = j;
				Maze[i][j] = '*';
			}
		}
	}
	//开始搜索
	queue<State> Q;
	Q.push(State(sx, sy, 0, 0));
	visited[sx][sy][0] = 1;
	int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	while(!Q.empty()) {
		int curr_x, curr_y, curr_step, curr_key;
		curr_x = Q.front().x;
		curr_y = Q.front().y;
		curr_step = Q.front().step;
		curr_key = Q.front().key;
		Q.pop();
		for(int i = 0; i < 4; i++) {
			int next_x = curr_x + move[i][0];
			int next_y = curr_y + move[i][1];
			if(next_x == tx && next_y == ty) {
				cout << curr_step + 1 << endl;
				return 0;
			}
			else if(next_x >= 0 && next_y >= 0 && next_x < rows && next_y < cols && 
				 Maze[next_x][next_y] == '*' && visited[next_x][next_y][0] == 0) {
				Q.push(State(next_x, next_y, curr_step+1, 0));
				visited[next_x][next_y][0] = 1;	
			}
			else if(next_x >= 0 && next_y >= 0 && next_x < rows && next_y < cols &&
				 Maze[next_x][next_y] == 'K' && visited[next_x][next_y][0] == 0) {
				Q.push(State(next_x, next_y, curr_step+1, 1));
				visited[next_x][next_y][0] = 1;
				visited[next_x][next_y][1] = 1;
			}
			else if(next_x >= 0 && next_y >= 0 && next_x < rows && next_y < cols &&
				 (Maze[next_x][next_y] == '*' || Maze[next_x][next_y] == 'D') && 
				 visited[next_x][next_y][1] == 0 && curr_key == 1) {
				Q.push(State(next_x, next_y, curr_step+1, 1));
				visited[next_x][next_y][1] = 1;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}



