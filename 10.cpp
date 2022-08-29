#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> turn(vector<vector<int>> arr) {
    int arrS = arr.size();
    vector<vector<int>> tmp(arrS, vector<int>(arrS));
    for (int i = 0; i < arrS; ++i) {
        for (int j = 0; j < arrS; ++j) {
            tmp[j][arrS - 1 - i] = arr[i][j];
        }
    }
    return tmp;
}

bool check(vector<vector<int>> lock) {
    int lockS = lock.size() / 3;
    for (int i = lockS; i < lockS * 2; ++i) {
        for (int j = lockS; j < lockS * 2; ++j) {
            if (lock[i][j] == 1) continue;
            return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    //bool answer = true;
    //return answer;
    int lockS = lock.size();
    vector<vector<int>> newLock(lockS * 3, vector<int>(lockS * 3));
    for (int i = 0; i < lockS; ++i) {
        for (int j = 0; j < lockS; ++j) {
            newLock[i + lockS][j + lockS] = lock[i][j];
        }
    }

    for (int i = 0; i < lockS * 2; ++i) {
        for (int j = 0; j < lockS * 2; ++j) {
            for (int k = 0; k < 4; ++k) {
                key = turn(key);
                vector<vector<int>> memo(key.size(), vector<int>(key.size()));
                for (int r = 0; r < key.size(); ++r) {
                    for (int c = 0; c < key.size(); ++c) {
                        memo[r][c] = newLock[r + i][c + j];
                        newLock[r + i][c + j] += key[r][c];
                        if (check(newLock)) return true;
                    }
                }
                for (int r = 0; r < key.size(); ++r) {
                    for (int c = 0; c < key.size(); ++c) {
                        newLock[r + i][c + j] = memo[r][c];
                    }
                }
            }
        }
    }
    return false;
}
