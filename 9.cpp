#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 1e9;

    for (int i = 1; i <= s.size() / 2 + 1; ++i) {
        string compressed, prevS;
        int cnt = 1;
        for (int j = 0; j < s.size(); j += i) {
            string curS;
            for (int t = j; t < i + j; t++) {
                if (t > s.size() - 1) continue;
                 curS += s[t];
            }
            if (curS == prevS) {
                cnt++;
            }
            else {
                if (cnt > 1 && j != 0) {
                    compressed += to_string(cnt) + prevS;
                }
                else {
                    compressed += prevS;
                }
                cnt = 1;
                prevS = curS;
            }
        }
        if (cnt > 1) compressed += to_string(cnt) + prevS;
        else compressed += prevS;
        int cSize = compressed.size();
        answer = min(answer, cSize);
    }
    return answer;
}

int main() {
    string s = "abcabcdede";
    cout << solution(s);
}