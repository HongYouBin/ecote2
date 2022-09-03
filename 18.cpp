#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string p) {
    if (p == "") return p;
    string answer = "";
    string u, v;
    int openCnt = 0, closeCnt = 0;
    stack<char> st;
    if (p[0] == '(') {
        openCnt++;
        st.push('(');
    }
    else closeCnt++;
    u += p[0];

    for (int i = 1; i < p.size(); ++i) {
        if (openCnt == closeCnt) break;
        u += p[i];
        if (p[i] == '(') {
            openCnt++;
            st.push('(');
        }
        else {
            closeCnt++;
            if (!st.empty()) st.pop();
        }
    }
    for (int i = u.size(); i < p.size(); ++i) v += p[i];
    if (st.empty()) {
        return u + solution(v);
    }
    else {
        string newU = "";
        for (int i = 1; i < u.size() - 1; ++i) {
            if (u[i] == '(')newU += ')';
            else newU += '(';
        }
        return "(" + solution(v) + ")" + newU;
    }
}
