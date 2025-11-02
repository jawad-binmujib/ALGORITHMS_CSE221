#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        long long num1, num2;
        cin >> num1 >> num2;
        long long num_of_skips = (num1 - 1) / (num2 - 1);
        long long answer = num1 + num_of_skips;
        cout << answer << endl;
    }
    return 0;
}