#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

int n;
int map[21][21];
int visited[21][21];
int used_dessert[101];
int starty, startx;
int dy[4] = { 1,1,-1,-1 };
int dx[4] = { -1,1,1,-1 };
int maxi = -0x7f7f7f;

void solve(int lev, int nowy, int nowx, int direction) {

	for (int i = 0; i < 2; i++) {
		if (direction + i >= 4) continue;

		int ny = nowy + dy[direction + i];
		int nx = nowx + dx[direction + i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (ny == starty && nx == startx) {
			if (lev + 1 > maxi) {
				maxi = lev + 1;
				int d = 0;
			}
			break;
		}
		if (visited[ny][nx] == 1) continue;
		if (used_dessert[map[ny][nx]] == 1) continue;

		visited[ny][nx] = 1;
		used_dessert[map[ny][nx]] = 1;

		solve(lev + 1, ny, nx, direction + i);
		visited[ny][nx] = 0;
		used_dessert[map[ny][nx]] = 0;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//init
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		memset(used_dessert, 0, sizeof(used_dessert));
		maxi = -1;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				starty = i; startx = j;
				visited[i][j] = 1;
				used_dessert[map[i][j]] = 1;
				solve(0, i, j, 0);
				visited[i][j] = 0;
				used_dessert[map[i][j]] = 0;
			}
		}
		printf("#%d %d\n", test_case, maxi);
	}
	return 0;
}