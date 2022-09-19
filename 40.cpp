#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define inf 1e9
using namespace std;

int n, m, dist[200001];
vector<int> vt[20001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int a, b;
	cin >> n >> m;
	fill(dist, dist + n + 1, inf);

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		vt[a].push_back(b);
		vt[b].push_back(a);
	}
	priority_queue<pair<int, int>> pq;
	dist[1] = 0;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int cst = -pq.top().first;
		int num = pq.top().second; pq.pop();
		if (dist[num] < cst) continue;
		for (auto nxt : vt[num]) {
			if (dist[nxt] < cst + 1) continue;
			dist[nxt] = cst + 1;
			pq.push({ -(cst + 1), nxt });
		}
	}

	int cnt = 1;
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		if (dist[i] > dist[ans]) {
			ans = i;
			cnt = 1;
		}
		else if (dist[i] == dist[ans])cnt++;
	}
	cout << ans << ' ' << dist[ans] << ' ' << cnt << '\n';
}