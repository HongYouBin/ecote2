#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define pii pair<int, int>
#define pis pair<int, string>
using namespace std;

int n, k, l, arr[105][105], dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
queue<pis> dirQue;
queue<pii> pos;

int direction(string s, int num) {
	if (s == "D") {
		num++;
		if (num == 4) num = 0;
	}
	else {
		num--;
		if (num == -1) num = 3;
	}
	return num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	int x, y;
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		arr[x - 1][y - 1] = 2;
	}
	cin >> l;
	string dir;
	for (int i = 0; i < l; ++i) {
		cin >> x >> dir;
		dirQue.push({ x, dir });
	}
	//sort(dirVt.begin(), dirVt.end());
	int endT = 0, dirNum = 0;
	pii curPos = { 0, 0 };
	arr[0][0] = 1;
	pos.push(curPos);
	while (true) {
		if (!dirQue.empty() && endT == dirQue.front().first) {
			dirNum = direction(dirQue.front().second, dirNum);
			dirQue.pop();
		}
		int nxtX = curPos.first + dx[dirNum];
		int nxtY = curPos.second + dy[dirNum];
		pos.push({ nxtX, nxtY });
		if (arr[nxtX][nxtY] == 2) {
			arr[pos.front().first][pos.front().second] = 1;
			//pos.pop();
		}
		else if (arr[nxtX][nxtY] == 0) {
			arr[pos.front().first][pos.front().second] = 0;
			pos.pop();
		}
		curPos = { nxtX, nxtY };
		endT++;

		if (arr[nxtX][nxtY] == 1 || nxtX < 0 || n <= nxtX || nxtY < 0 || n <= nxtY) {
			cout << endT << '\n';
			return 0;
		}
		arr[curPos.first][curPos.second] = 1;

	}
}