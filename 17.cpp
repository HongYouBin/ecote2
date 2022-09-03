#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

#define ppp pair<pair<int, int>, pair<int, int>>
#define pip pair<int, pair<int, int>>
using namespace std;

int n, k, s, x, y, map[201][201][2], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
queue<ppp> q;

int main() {
	cin >> n >> k;
	vector<pip> vt;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j][0];
			if (map[i][j][0]) vt.push_back({ map[i][j][0], {i, j} });
		}
	}
	cin >> s >> x >> y;
	sort(vt.begin(), vt.end());
	for (auto& v : vt) {
		q.push({ {v.first, 0}, {v.second.first, v.second.second} });
	}
	while (!q.empty()) {
		int num = q.front().first.first;
		int ti = q.front().first.second;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || n <= nx || ny < 0 || n <= ny || map[nx][ny][0]) continue;
			map[nx][ny][0] = num;
			map[nx][ny][1] = ti + 1;
			q.push({ {num, ti + 1}, {nx, ny} });
		}
	}
	if (map[x - 1][y - 1][1] > s)cout << "0" << '\n';
	else cout << map[x - 1][y - 1][0] << '\n';
}