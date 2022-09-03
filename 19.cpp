#include <iostream>
#include <vector>
#include <queue>

#define pip pair<pair<int, int>, pair<int,int>>
using namespace std;

int n, ope[4], arr[15], minAns = 1e9, maxAns = -1e9;

void resolve(int idx, int num, int plus, int minus, int mul, int div) {
	if (n == idx) {
		minAns = min(minAns, num);
		maxAns = max(maxAns, num);
	}

	if (plus) resolve(idx + 1, num + arr[idx], plus - 1, minus, mul, div);
	if (minus) resolve(idx + 1, num - arr[idx], plus, minus - 1, mul, div);
	if (mul) resolve(idx + 1, num * arr[idx], plus, minus, mul - 1, div);
	if (div) resolve(idx + 1, num / arr[idx], plus, minus, mul, div - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)cin >> arr[i];
	for (int i = 0; i < 4; ++i)cin >> ope[i];
	resolve(1, arr[0], ope[0], ope[1], ope[2], ope[3]);
	cout << maxAns << '\n' << minAns << '\n';
}