#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<string> words(n);
        set<char> unique_chars;
        
        for (int i = 0; i < n; i++) {
            cin >> words[i];
            for (char c : words[i]) {
                unique_chars.insert(c);
            }
        }

        map<char, vector<char>> adj;
        map<char, int> in_degree;
        for (char c : unique_chars) {
            in_degree[c] = 0;
        }

        for (int i = 0; i < n - 1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            
            int len = min(w1.length(), w2.length());
            bool found_diff = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    in_degree[w2[j]]++;
                    found_diff = true;
                    break;
                }
            }

            if (!found_diff && w1.length() > w2.length()) {
                cout << "-1" << endl;
                return 0;
            }
        }

        priority_queue<char, vector<char>, greater<char>> pq;

        for (char c : unique_chars) {
            if (in_degree[c] == 0) {
                pq.push(c);
            }
        }

        string result = "";
        while (!pq.empty()) {
            char u = pq.top();
            pq.pop();
            result += u;

            for (char v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    pq.push(v);
                }
            }
        }

        if (result.length() == unique_chars.size()) {
            cout << result << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}