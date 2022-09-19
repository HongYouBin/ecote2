#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define mo 1000000000
using namespace std;

int n, m, arr[501][501];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	int from, to, cst;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = 1e9;
		}
	}

	for (int i = 0; i < m; ++i) {
		cin >> from >> to >> cst;
		arr[from][to] = min(arr[from][to], cst);
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (arr[i][j] == 1e9 || i == j)cout << 0 << ' ';
			else cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}