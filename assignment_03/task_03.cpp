#include <iostream>
using namespace std;

long long binaryPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        
        base = (base * base) % mod;
        exp = exp / 2; 
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b;
    cin >> a >> b;
    long long mod = 107;

    cout << binaryPower(a, b, mod) << endl;
    
    return 0;
}