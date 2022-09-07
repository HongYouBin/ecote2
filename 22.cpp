#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define ppp pair<pair<int, int>, pair<int, int>>
#define pip pair<int, pair<int, int>>
#define pii pair<int,int>
using namespace std;

int visited[105][105][2], dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };

vector<pii> move(int row, int col, int row2, int col2, int type, int bSize, vector<vector<int>>& board) {
    vector<pii> vt;
    for (int i = 0; i < 4; ++i) {
        int nRow = row + dx[i], nRow2 = row2 + dx[i], nCol = col + dy[i], nCol2 = col2 + dy[i];
        if (nRow < 0 || bSize <= nRow || nCol < 0 || bSize <= nCol || board[nRow][nCol] || visited[nRow][nCol][type])continue;
        if (nRow2 < 0 || bSize <= nRow2 || nCol2 < 0 || bSize <= nCol2 || board[nRow2][nCol2])continue;
        vt.push_back({ nRow, nCol });
    }
    return vt;
}

vector<pii> turn(int row, int col, int type, int bSize, vector<vector<int>>& board) {
    vector<pii> vt;
    if (type) {
        if (0 <= col - 1 && !board[row + 1][col - 1] && !board[row][col - 1] && !visited[row][col - 1][!type]) vt.push_back({ row, col - 1 });
        if (0 <= col - 1 && !board[row][col - 1] && !board[row + 1][col - 1] && !visited[row + 1][col - 1][!type])vt.push_back({ row + 1, col - 1 });
        if (col + 1 < bSize && !board[row + 1][col + 1] && !board[row][col + 1] && !visited[row][col][!type])vt.push_back({ row, col });
        if (col + 1 < bSize && !board[row][col + 1] && !board[row + 1][col + 1] && !visited[row + 1][col][!type])vt.push_back({ row + 1, col });
    }
    else {
        if (0 <= row - 1 && !board[row - 1][col + 1] && !board[row - 1][col] && !visited[row - 1][col][!type])vt.push_back({ row - 1, col });
        if (0 <= row - 1 && !board[row - 1][col] && !board[row - 1][col + 1] && !visited[row - 1][col + 1][!type])vt.push_back({ row - 1, col + 1 });
        if (row + 1 < bSize && !board[row + 1][col] && !board[row + 1][col + 1] && !visited[row][col + 1][!type])vt.push_back({ row, col + 1 });
        if (row + 1 < bSize && !board[row + 1][col + 1] && !board[row + 1][col] && !visited[row][col][!type])vt.push_back({ row, col });
    }
    return vt;
}


int solution(vector<vector<int>> board) {
    int bSize = board.size();
    int answer = 0;
    queue<ppp> q;
    q.push({ {0, 0},{0, 0} });
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int ti = q.front().first.first, type = q.front().first.second;
        int row = q.front().second.first, col = q.front().second.second; 
        q.pop();
        int row2, col2;
        if (type) {
            row2 = row + 1;
            col2 = col;
        }
        else {
            row2 = row;
            col2 = col + 1;
        }
        if ((row == bSize - 1 && col == bSize - 1) || (row2 == bSize - 1 && col2 == bSize - 1)) {
            answer = ti;
            return answer;
        }

        vector<pii> nMove = move(row, col, row2, col2, type, bSize, board);
        if (!nMove.empty()) {
            for (auto& i : nMove) {
                q.push({ {ti + 1, type}, {i.first, i.second} });
                visited[i.first][i.second][type] = 1;
            }
        }
        vector<pii> nTurn = turn(row, col, type, bSize, board);
        if (!nTurn.empty()) {
            for (auto& i : nTurn) {
                q.push({ {ti + 1, !type}, {i.first, i.second} });
                visited[i.first][i.second][!type] = 1;
            }
        }
    }
}

int main() {
    vector<vector<int>> vt(5, vector<int>(5));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> vt[i][j];
        }
    }
    cout << solution(vt);
}