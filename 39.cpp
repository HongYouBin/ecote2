#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define inf 1e9
using namespace std;

int t, n, arr[130][130], visited[130][130], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				visited[i][j] = inf;
			}
		}

		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -arr[0][0], {0, 0} });
		visited[0][0] = arr[0][0];
		while (!pq.empty()) {
			int cst = -pq.top().first;
			int r = pq.top().second.first;
			int c = pq.top().second.second; pq.pop();
			if (r == n - 1 && c == n - 1) break;
			for (int i = 0; i < 4; ++i) {
				int nxtR = r + dx[i], nxtC = c + dy[i];
				if (nxtR < 0 || n <= nxtR || nxtC < 0 || n <= nxtC || visited[nxtR][nxtC] != inf) continue;
				int nxtCst = cst + arr[nxtR][nxtC];
				visited[nxtR][nxtC] = nxtCst;
				pq.push({ -nxtCst, {nxtR, nxtC} });
			}
		}
		cout << visited[n - 1][n - 1] << '\n';
	}
}