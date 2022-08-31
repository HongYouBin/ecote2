#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int bFloor[105][105], column[105][105];
/*
bool comp(vector<int> a, vector<int> b) {
    if (a[0] != b[0]) return a[0] < b[0];
    else if (a[0] == b[0] && a[1] != b[1]) return a[1] < b[1];
    else if (a[2] != b[2]) return a[2] < b[2];
}
*/
//column = x, row = y
void check(int c, int r, int isbFloor) {
    if (isbFloor && (column[r - 1][c] || column[r - 1][c + 1] || (bFloor[r][c - 1] && bFloor[r][c + 1]))) {
        bFloor[r][c] = 1;
    } 
    if (!isbFloor && (r == 0 || bFloor[r][c - 1] || bFloor[r][c] || column[r - 1][c])) {
        column[r][c] = 1;
    }
}

void delFrame(int c, int r, int isbFloor, int arrSize){
    if (isbFloor) bFloor[r][c] = 0;
    else column[r][c] = 0;
    bool flag = true;
    for (int i = 0; i <= arrSize; ++i) {
        for (int j = 0; j <= arrSize; ++j) {
            if (bFloor[i][j] && !(column[i - 1][j] || column[i - 1][j + 1] || (bFloor[i][j - 1] && bFloor[i][j + 1]))) flag = false;
            if (column[i][j] && !(i == 0 || bFloor[i][j - 1] || bFloor[i][j] || column[i - 1][j])) flag = false;
        }
    }
    if (!flag) {
        if (isbFloor) bFloor[r][c] = 1;
        else column[r][c] = 1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> ans;

    for (int i = 0; i < build_frame.size(); ++i) {
        vector<int> build = build_frame[i];
        if (build[3]) {
            check(build[0], build[1], build[2]);
        }
        else delFrame(build[0], build[1], build[2], n);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (bFloor[i][j]) {
                vector<int> inp;
                inp.push_back(j);
                inp.push_back(i);
                inp.push_back(1);
                ans.push_back(inp);
            }
            if (column[i][j]) {
                vector<int> inp;
                inp.push_back(j);
                inp.push_back(i);
                inp.push_back(0);
                ans.push_back(inp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

