#include <iostream>
#include <vector>
using namespace std;

int n, m, parent[201];
vector<int> vt[201], city;

int find(int num) {
	if (num != parent[num]) return parent[num] = find(parent[num]);
	else return num;
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	int inp;
	
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		for (int j = 1; j <= n; ++j) {
			cin >> inp;
			if (inp) {
				vt[i].emplace_back(j);
				vt[j].emplace_back(i);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (auto node : vt[i]) {
			if (find(i) == find(node)) continue;
			merge(i, node);
		}
	}
	//cin >> inp;
	//int num = find(inp);
	for (int i = 0; i < m; ++i) {
		cin >> inp;
		city.emplace_back(inp);
	}
	for (int i = 1; i < m; ++i) {
		if (find(city[i - 1]) != find(city[i])) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}