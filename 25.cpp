#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[505];

bool cmp(pair<double, int> a, pair<double, int> b) {
    if (a.first != b.first) return a.first > b.first;
    else if (a.first == b.first) return a.second < b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for (auto& i : stages) arr[i]++;
    int cnt = stages.size();
    vector<pair<double, int>> vt;

    for (int i = 1; i <= N; ++i) {
        double fail;
        if (cnt) fail = (double)arr[i] / cnt;
        else fail = 0;
        cnt -= arr[i];
        vt.push_back({ fail, i });
    }
    sort(vt.begin(), vt.end(), cmp);
    for (auto& i : vt) {
        answer.push_back(i.second);
    }
    return answer;
}