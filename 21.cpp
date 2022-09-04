#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, l, r, map[55][55], visited[55][55], memo[55][55], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

void bfs(int ro, int co) {
	int cnt = 0, sum = 0;
	queue<pair<int, int>> q;
	vector<pair<int, int>> vt;

	visited[ro][co] = 1;
	sum += map[ro][co];
	cnt++;
	vt.push_back({ ro, co });
	q.push({ ro, co });

	while (!q.empty()) {
		int curR = q.front().first, curC = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nxtR = curR + dx[i];
			int nxtC = curC + dy[i];
			int gap = abs(map[curR][curC] - map[nxtR][nxtC]);
			if (nxtR < 0 || n <= nxtR || nxtC < 0 || n <= nxtC || visited[nxtR][nxtC] || !(l <= gap && gap <= r))continue;
			sum += map[nxtR][nxtC];
			cnt++;
			visited[nxtR][nxtC] = 1;
			vt.push_back({ nxtR, nxtC });
			q.push({ nxtR, nxtC });
		}
	}
	for (auto& i : vt) {
		map[i.first][i.second] = sum / cnt;
	}
}

int solv() {
	int day = 0;
	while (true) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				visited[i][j] = 0;
				memo[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (visited[i][j]) continue;
				bfs(i, j);
			}
		}

		bool flag = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (memo[i][j] != map[i][j]) flag = false;
			}
		}
		if (flag) break;
		day++;
	}
	return day;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cin >> map[i][j];
	}
	cout << solv() << '\n';
}