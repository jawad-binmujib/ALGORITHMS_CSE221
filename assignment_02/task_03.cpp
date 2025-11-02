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

    vector<pair<long long, int>> arr1(length);
    for (int i = 0; i < length; ++i) {
        cin >> arr1[i].first; 
        arr1[i].second = i + 1; 
    }
    sort(arr1.begin(), arr1.end());
    for (int i = 0; i < length - 2; ++i) {
        int left_pointer = i + 1;      
        int right_pointer = length - 1;
        long long two_sum = targeted_sum - arr1[i].first;

        while (left_pointer < right_pointer) {
            long long sum = arr1[left_pointer].first + arr1[right_pointer].first;
            if (sum == two_sum) {
                cout << arr1[i].second << " " << arr1[left_pointer].second << " " << arr1[right_pointer].second << endl;
                return 0; 
            }
            else if (sum < two_sum) {
                left_pointer+=1;
            }
            else { 
                right_pointer--;
            }
        }
    }

    cout << "-1" << endl;
    return 0;
}