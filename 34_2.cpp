#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int inp;
	vector<int> arr(n), line;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		arr[i] = -inp;
	}
	line.push_back(-1e9);

	for (int i = 0; i < n; ++i) {
		if (line.back() < arr[i])line.push_back(arr[i]);
		else {
			int idx = lower_bound(line.begin(), line.end(), arr[i]) - line.begin();
			line[idx] = arr[i];
		}
	}
	cout << n - line.size() + 1 << '\n';
}