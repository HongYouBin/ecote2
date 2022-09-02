#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define inf 1e9
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int ans = inf;
    vector<int> newWeak;
    for (auto& i : weak) {
        newWeak.push_back(i);
        newWeak.push_back(i + n);
    }
    sort(newWeak.begin(), newWeak.end());
    sort(dist.begin(), dist.end(), greater<>());
    do {
        for (int i = 0; i < weak.size(); ++i) {
            int prev = 0, idx = 0;
            for (int j = i; j < i + weak.size(); ++j) {
                if (prev < newWeak[j]) {
                    if (idx < dist.size())prev = newWeak[j] + dist[idx++];
                    else {
                        idx = inf;
                        break;
                    }
                }
            }
            ans = min(ans, idx);
        }
    } while (next_permutation(dist.begin(), dist.end()));
    if (ans == inf) return -1;
    else return ans;
}

int main() {
    vector<int> w, d;
    int n = 15;
    w.push_back(1);
    w.push_back(7);
    d.push_back(3);
    cout << solution(n, w, d);
}