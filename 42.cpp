#include <iostream>
#include <vector>
using namespace std;

int g, p, parent[100001];

int findParent(int num) {
	if (num != parent[num]) return parent[num] = findParent(parent[num]);
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

	cin >> g >> p;
	for (int i = 1; i <= g; ++i)parent[i] = i;

	int x, ans = 0;
	for (int i = 0; i < p; ++i) {
		cin >> x;
		if (findParent(x) == 0) break;
		ans++;
		merge(findParent(x), findParent(x) - 1);
	}
	cout << ans << '\n';
}