#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	vector<int> vt(n);
	for (int i = 0; i < n; ++i) cin >> vt[i];
	sort(vt.begin(), vt.end());
	int vSize = vt.size() - 1;
	cout << vt[vSize / 2] << '\n';
}