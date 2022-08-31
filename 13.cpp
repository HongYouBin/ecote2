#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define pii pair<int,int>
using namespace std;

int n, m, map[55][55], ans = 1e9;

int main() {
	cin >> n >> m;
	vector<pii> chicken;
	vector<pii> house;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 2) chicken.push_back({ i, j });
			else if (map[i][j] == 1)house.push_back({ i, j });
		}
	}
	vector<int> bin(chicken.size());
	fill(bin.end() - m, bin.end(), 1);
	do {
		int totalDist = 0;
		vector<pii> mChicken;
		for (int i = 0; i < bin.size(); ++i) {
			if (!bin[i]) continue;
			mChicken.push_back(chicken[i]);
		}
		for (int i = 0; i < house.size(); ++i) {
			int minDist = 1e9;
			for (int j = 0; j < mChicken.size(); ++j) {
				int dist = abs(house[i].first - mChicken[j].first) + abs(house[i].second - mChicken[j].second);
				minDist = min(minDist, dist);
			}
			totalDist += minDist;
		}
		ans = min(ans, totalDist);
	} while (next_permutation(bin.begin(), bin.end()));
	cout << ans << '\n';
}