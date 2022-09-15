#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s1, s2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s1 >> s2;
	vector<vector<int>> arr(s1.size() + 1, vector<int>(s2.size() + 1));
	for (int i = 0; i <= s1.size(); ++i)arr[i][0] = i;
	for (int i = 0; i <= s2.size(); ++i)arr[0][i] = i;

	for (int i = 1; i <= s1.size(); ++i) {
		for (int j = 1; j <= s2.size(); ++j) {
			if (s1[i - 1] == s2[j - 1]) arr[i][j] = arr[i - 1][j - 1];
			else arr[i][j] = min({ arr[i][j - 1], arr[i - 1][j], arr[i - 1][j - 1] }) + 1;
		}
	}
	cout << arr[s1.size()][s2.size()] << '\n';
}