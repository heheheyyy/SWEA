#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

enum Type {
	N = 0, S = 1
};
enum Dir {
	Clock = 1, Counterclock = -1
};

int k;
int magnets[4][8];
int visited[4];

void rotate(int magnet, int dir) {
	if (dir == Clock) {
		int tmp = magnets[magnet][7];
		for (int i = 7; i > 0; i--) {
			magnets[magnet][i] = magnets[magnet][i - 1];
		}
		magnets[magnet][0] = tmp;
	}
	else if (dir == Counterclock) {
		int tmp = magnets[magnet][0];
		for (int i = 0; i < 7; i++) {
			magnets[magnet][i] = magnets[magnet][i + 1];
		}
		magnets[magnet][7] = tmp;
	}
}

void solve(int nowM, int nowIdx, int nowDir, int nextM) {
	int c_magnets[4][8] = { 0, };
	memcpy(c_magnets, magnets, sizeof(magnets));
	rotate(nowM, nowDir);

	if (nextM < 0 || nextM >= 4) return;
	if (visited[nextM] == 1) return;
	int nextIdx = (nowIdx + 4) % 8;
	if (c_magnets[nowM][nowIdx] == c_magnets[nextM][nextIdx]) return;

	int nextDir = 0;
	if (nowDir == Clock) nextDir = Counterclock;
	if (nowDir == Counterclock) nextDir = Clock;

	visited[nextM] = 1;
	//오른쪽
	solve(nextM, (nowIdx + 4) % 8, nextDir, nextM + 1);
	//왼쪽
	solve(nextM, (nowIdx + 4) % 8, nextDir, nextM - 1);
	visited[nextM] = 0;

}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnets[i][j];
			}
		}

		while (k--) {
			int targetM, dir;
			cin >> targetM >> dir;
			targetM--;

			// targetM-1의 양쪽 자석 중 돌릴 게 있는지 확인
			// 오른쪽
			visited[targetM] = 1;
			solve(targetM, 2, dir, targetM + 1);
			// 왼쪽
			solve(targetM, 6, dir, targetM - 1);
			visited[targetM] = 0;
		}

	}
	return 0;
}