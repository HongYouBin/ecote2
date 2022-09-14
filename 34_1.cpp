#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	vector<int> arr(n), dp(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] < arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int num = 0;
	for (int i = 0; i < n; ++i) num = max(num, dp[i]);
	cout << n - num << '\n';
}