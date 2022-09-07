#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> x;
	vector<int> vt(n);
	for (int i = 0; i < n; ++i)cin >> vt[i];
	int fIdx = lower_bound(vt.begin(), vt.end(), x) - vt.begin();
	int sIdx = upper_bound(vt.begin(), vt.end(), x) - vt.begin();
	if (sIdx == fIdx) cout << -1 << '\n';
	else cout << sIdx - fIdx << '\n';
}