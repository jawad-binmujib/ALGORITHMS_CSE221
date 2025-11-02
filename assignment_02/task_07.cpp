#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int length, numb;
    cin >> length >> numb;
    vector<long long> arr1(length);
    for (int i = 0; i < length; i++) {
        cin >> arr1[i];
    }
    for (int k = 0; k < numb; k++) {
        long long range1, range2;
        cin >> range1 >> range2;
        auto range_start = lower_bound(arr1.begin(), arr1.end(), range1);
        auto range_end = upper_bound(arr1.begin(), arr1.end(), range2);
        long long count = range_end - range_start;
        std::cout << count << endl;
    }
    return 0;
}