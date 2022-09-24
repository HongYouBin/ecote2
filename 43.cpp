#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, parent[200001];

int findParent(int num) {
	if (parent[num] != num) return parent[num] = findParent(parent[num]);
	else return num;
}

void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		for (int i = 1; i <= m; ++i)parent[i] = i;

		int x, y, z, totalCst = 0, cst = 0;
		vector<pair<int, pair<int, int>>> vt;

		for (int i = 0; i < n; ++i) {
			cin >> x >> y >> z;
			vt.push_back({ z, {x, y} });
			totalCst += z;
		}
		sort(vt.begin(), vt.end());
		for (auto& i : vt) {
			int house1 = i.second.first;
			int house2 = i.second.second;
			if (findParent(house1) == findParent(house2)) continue;
			cst += i.first;
			merge(house1, house2);
		}
		cout << totalCst - cst << '\n';
	}
}