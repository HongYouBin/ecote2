#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, map[10][10];

bool check(vector<pair<int, int>> teacher) {
	for (auto& t : teacher) {
		int curR = t.first, curC = t.second;
		int nxtR = curR, nxtC = curC;
		for (int i = 0; i < n; ++i) {
			nxtC++;
			if (n <= nxtC || map[nxtR][nxtC] == -1) break;
			if (map[nxtR][nxtC] == 1) return false;
		}
		nxtR = curR, nxtC = curC;
		for (int i = 0; i < n; ++i) {
			nxtC--;
			if (nxtC < 0 || map[nxtR][nxtC] == -1) break;
			if (map[nxtR][nxtC] == 1) return false;
		}
		nxtR = curR, nxtC = curC;
		for (int i = 0; i < n; ++i) {
			nxtR++;
			if (n <= nxtR || map[nxtR][nxtC] == -1) break;
			if (map[nxtR][nxtC] == 1) return false;
		}
		nxtR = curR, nxtC = curC;
		for (int i = 0; i < n; ++i) {
			nxtR--;
			if (nxtR < 0 || map[nxtR][nxtC] == -1) break;
			if (map[nxtR][nxtC] == 1) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	bool ans = false;
	cin >> n;
	char inp;
	vector<pair<int, int>> emp;
	vector<pair<int, int>> teacher;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> inp;
			if (inp == 'X') {
				map[i][j] = 0;
				emp.push_back({ i, j });
			}
			else if (inp == 'S') map[i][j] = 1;
			else {
				map[i][j] = 2;
				teacher.push_back({ i, j });
			}
		}
	}
	vector<int> bin(emp.size());
	fill(bin.end() - 3, bin.end(), 1);
	do {
		vector<pair<int, int>> memo;
		for (int i = 0; i < bin.size(); ++i) {
			if (!bin[i]) continue;
			int r = emp[i].first, c = emp[i].second;
			memo.push_back({ r, c });
			map[r][c] = -1;
		}
		if (check(teacher)) {
			ans = true;
			break;
		}
		for (auto& i : memo) {
			map[i.first][i.second] = 0;
		}
	} while (next_permutation(bin.begin(), bin.end()));

	if (ans) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}