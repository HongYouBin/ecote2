#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int TC, n, t, m, a, b, arr[501][501], visited[501], cnt[501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> TC;
	while (TC--) {
		vector<int> ans;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			visited[i] = 0;
			cnt[i] = 0;
			for (int j = 1; j <= n; ++j) {
				arr[i][j] = 0;
			}
		}
		int num;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			visited[num] = 1;
			for (int j = 1; j <= n; ++j) {
				if (visited[j]) continue;
				arr[num][j] = 1;
				cnt[j]++;
			}
		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			if (arr[a][b] == 1) {
				arr[a][b] = 0;
				arr[b][a] = 1;
				cnt[b]--;
				cnt[a]++;
			}
			else {
				arr[a][b] = 1;
				arr[b][a] = 0;
				cnt[b]++;
				cnt[a]--;
			}
		}
		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (cnt[i] == 0)q.push(i);
		}
		for (int i = 1; i <= n; ++i) {
			if (q.size() > 1) {
				cout << '?' << '\n';
				break;
			}
			else if (q.size() == 0) {
				cout << "IMPOSSIBLE" << '\n';
				break;
			}
			int cur = q.front(); q.pop();
			ans.push_back(cur);
			for (int j = 1; j <= n; ++j) {
				if (arr[cur][j]) {
					cnt[j]--;
					if (!cnt[j]) q.push(j);
				}
			}
		}
		if (ans.size() == n) {
			for (auto& i : ans) {
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
}