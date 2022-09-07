#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> c;
	vector<int> vt(n);
	for (int i = 0; i < n; ++i)cin >> vt[i];
	sort(vt.begin(), vt.end());
	int ans;

	int start = 0, end = vt[n - 1];
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 1, prevNum = vt[0];
		for (int i = 1; i < n; ++i) {
			if (vt[i] - prevNum < mid) continue;
			cnt++;
			prevNum = vt[i];
		}
		if (cnt >= c) {
			start = mid + 1;
			ans = mid;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ans << '\n';
}