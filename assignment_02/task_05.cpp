#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length;
    long long targeted_sum;
    cin >> length >> targeted_sum;
    vector<int> arr1(length);
    for (int i = 0; i < length; i++) {
        cin >> arr1[i];
    }

    int left_pointer = 0;           
    int max_length = 0;     
    long long current_sum = 0; 
    for (int i = 0; i < length; i++) {
        current_sum += arr1[i];
        while (current_sum > targeted_sum) {
            current_sum -= arr1[left_pointer];
            left_pointer += 1;
        }

        max_length = max(max_length, i - left_pointer + 1);
    }
    cout << max_length << endl;
    return 0;
}