#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, dp[20], t[20], p[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> p[i];
	}

	int ans = 0;
	for (int i = n; 1 <= i; --i) {
		if (n < i + t[i] - 1) {
			dp[i] = ans;
			continue;
		}
		dp[i] = dp[i + t[i]] + p[i];
		ans = dp[i] = max(ans, dp[i]);
	}
	cout << ans << '\n';
}