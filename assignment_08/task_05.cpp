#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Activity {
    int s, e;
};

bool compare(const Activity& a, const Activity& b) {
    if (a.e != b.e) return a.e < b.e;
    return a.s < b.s;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<Activity> acts(n);
        for (int i = 0; i < n; i++) {
            cin >> acts[i].s >> acts[i].e;
        }

        sort(acts.begin(), acts.end(), compare);

        multiset<int> people_finish_times;
        for (int i = 0; i < m; i++) people_finish_times.insert(0);

        int count = 0;
        for (const auto& act : acts) {
            auto it = people_finish_times.upper_bound(act.s);

            if (it != people_finish_times.begin()) {
                it--;
                
                people_finish_times.erase(it);
                people_finish_times.insert(act.e);
                count++;
            }
        }
        cout << count << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}