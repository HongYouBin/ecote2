#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	int inp;
	for (int i = 0; i < n; ++i) {
		cin >> inp;
		pq.push(-inp);
	}

	int ans = 0;
	while (pq.size()>=2) {
		int fir = pq.top(); pq.pop();
		int sec = pq.top(); pq.pop();
		ans += fir + sec;
		pq.push(fir + sec);
	}
	cout << -ans << '\n';
}