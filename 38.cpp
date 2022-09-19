#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define mo 1000000000
using namespace std;

int n, m, arr[501][501], dArr[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	int fro, to;
	for (int i = 0; i < m; ++i) {
		cin >> fro >> to;
		arr[fro][to] = 1;
		dArr[to][fro] = 1;
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
				if (dArr[i][k] && dArr[k][j]) dArr[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (arr[i][j]) cnt++;
			if (dArr[i][j]) cnt++;
		}
		if (cnt == n - 1) ans++;
	}
	cout << ans << '\n';
}