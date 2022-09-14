#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string getA(string query) {
    for (int i = 0; i < query.size(); ++i) {
        if (query[i] == '?') {
            query[i] = 'a';
        }
    }
    return query;
}

string getZ(string query) {
    for (int i = 0; i < query.size(); ++i) {
        if (query[i] == '?') {
            query[i] = 'z';
        }
    }
    return query;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    vector<string> newWords[10001], revWords[10001], revQueries;

    //sort(words.begin(), words.end());
    for (auto& i : words) {
        newWords[i.size()].push_back(i);
        string s = "";
        for (int j = i.size() - 1; 0 <= j; --j) {
            s += i[j];
        }
        revWords[s.size()].push_back(s);
    }
    for (int i = 1; i <= 10000; ++i) {
        sort(newWords[i].begin(), newWords[i].end());
        sort(revWords[i].begin(), revWords[i].end());
    }
    
    for (auto& i : queries) {
        string s = "";
        for (int j = i.size() - 1; 0 <= j; --j) {
            s += i[j];
        }
        revQueries.push_back(s);
    }

    for (int i = 0; i < queries.size();++i) {
        string query = queries[i];
        string revQu = revQueries[i];
        if (query[0] != '?') {
            string aStr = getA(query);
            int start = lower_bound(newWords[aStr.size()].begin(), newWords[aStr.size()].end(), aStr) - newWords[aStr.size()].begin();
            string zStr = getZ(query);
            int en = upper_bound(newWords[aStr.size()].begin(), newWords[aStr.size()].end(), zStr) - newWords[aStr.size()].begin();
            answer.push_back(en - start);
        }
        else {
            string aStr = getA(revQu);
            int start = lower_bound(revWords[aStr.size()].begin(), revWords[aStr.size()].end(), aStr) - revWords[aStr.size()].begin();
            string zStr = getZ(revQu);
            int en = upper_bound(revWords[aStr.size()].begin(), revWords[aStr.size()].end(), zStr) - revWords[aStr.size()].begin();
            answer.push_back(en - start);
        }
    }
    return answer;
}
}