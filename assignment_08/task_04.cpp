#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int s, e, id;
};


bool compareTasks(const Task& a, const Task& b) {
    if (a.e != b.e)
        return a.e < b.e;
    return a.s < b.s;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].s >> tasks[i].e;
        tasks[i].id = i;
    }

    sort(tasks.begin(), tasks.end(), compareTasks);

    vector<Task> selected;
    int last_end_time = -1; 

    
    for (const auto& t : tasks) {
        if (selected.empty() || t.s >= last_end_time) {
            selected.push_back(t);
            last_end_time = t.e;
        }
    }

    cout << selected.size() << endl;
    for (const auto& t : selected) {
        cout << t.s << " " << t.e << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}