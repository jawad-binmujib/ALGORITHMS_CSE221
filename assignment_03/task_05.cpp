#include <iostream>
using namespace std;

pair<long long, long long> solve(long long a, long long n, long long m) {
    // Base case: n = 0
    // The sum is 0, and a^0 is 1.
    if (n == 0) {
        return {0, 1};
    }
    
    // --- Recursive Step ---
    // First, compute the result for n/2
    ll k = n / 2;
    pair<ll, ll> half = solve(a, k, m);
    
    long long sum_k = half.first;  // S(k)
    long long pow_k = half.second; // a^k
    long long sum_2k = (sum_k * (1 + pow_k)) % m;
    long long pow_2k = (pow_k * pow_k) % m;
    
    if (n % 2 == 0) {
        return {sum_2k, pow_2k};
        
    } 
    else {
        long long pow_n = (pow_2k * a) % m;
        long long sum_n = (sum_2k + pow_n) % m;
        
        return {sum_n, pow_n};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        long long a, n, m;
        cin >> a >> n >> m;
        cout << solve(a, n, m).first << endl;
    }
    return 0;
}