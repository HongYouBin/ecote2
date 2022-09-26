#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>
#define pip pair<int, pair<int, int>>
using namespace std;

int n, x, y, z, parent[100001];
vector<pii> eX, eY, eZ;
vector<pip> vt;

int findParent(int num) {
	if (parent[num] != num) return parent[num] = findParent(parent[num]);
	return num;
}

void merge(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (b > a) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		cin >> x >> y >> z;
		eX.push_back({ x, i });
		eY.push_back({ y, i });
		eZ.push_back({ z, i });
	}
	sort(eX.begin(), eX.end());
	sort(eY.begin(), eY.end());
	sort(eZ.begin(), eZ.end());
	for (int i = 0; i < eX.size() - 1; i++) {
		vt.push_back({ abs(eX[i].first - eX[i + 1].first), {eX[i].second, eX[i + 1].second} });
	}
	for (int i = 0; i < eY.size() - 1; i++) {
		vt.push_back({ abs(eY[i].first - eY[i + 1].first), {eY[i].second, eY[i + 1].second} });
	}
	for (int i = 0; i < eZ.size() - 1; i++) {
		vt.push_back({ abs(eZ[i].first - eZ[i + 1].first), {eZ[i].second, eZ[i + 1].second} });
	}
	sort(vt.begin(), vt.end());
	int cst = 0;

	for (auto& i : vt) {
		if (findParent(i.second.second) == findParent(i.second.first)) continue;
		cst += i.first;
		merge(i.second.first, i.second.second);
	}
	cout << cst << '\n';
}