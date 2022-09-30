#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, arr[25][25], visited[25][25], candid[25][25];
int t = 0, eat = 0, level = 2, dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 };
pair<int, int> pos;

bool bfs() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visited[i][j] = 0;
			candid[i][j] = 1e9;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ pos, 0 });
	bool flag = false;
	visited[pos.first][pos.second] = 1;
	//int candid[25][25];

	while (!q.empty()) {
		auto curPos = q.front().first; 
		int cst = q.front().second; q.pop();
		if (0 < arr[curPos.first][curPos.second] && arr[curPos.first][curPos.second] < level) {
			flag = true;
			pos = curPos;
			arr[curPos.first][curPos.second] = 0;
			cout << curPos.first << ' ' << curPos.second << '\n';
			t += cst;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int nxRow = curPos.first + dx[i];
			int nxCol = curPos.second + dy[i];
			if (nxRow<0 || n <= nxRow || nxCol < 0 || n<= nxCol || visited[nxRow][nxCol] || arr[nxRow][nxCol]>level) continue;
			visited[nxRow][nxCol] = true;
			q.push({ { nxRow, nxCol }, cst + 1 });
		}
		
	}
	return flag;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				pos = { i, j };
				arr[i][j] = 0;
			}
		}
	}

	while (true) {
		if (bfs()) {
			eat++;
			if (eat == level) {
				level++;
				eat = 0;
			}
		}
		else break;
	}
	cout << t << '\n';
}
