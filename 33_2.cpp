#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, t[20], p[20], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> p[i];
	}

	for (int i = 1; i <= n + 1; ++i) {
		vector<int> bin(n + 1);
		fill(bin.end() - i, bin.end(), 1);
		do {
			int nxtDay = 0, sum = 0;
			for (int j = 1; j <= n; ++j) {
				if (!bin[j] || j < nxtDay || n + 1 < j + t[j]) continue;
				sum += p[j];
				nxtDay = j + t[j];
			}
			ans = max(ans, sum);
		} while (next_permutation(bin.begin(), bin.end()));
	}
	cout << ans << '\n';
}