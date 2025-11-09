#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>     
using namespace std;

long long mergeSortAndCount(vector<int>& arr1, int left, int right) {

    if (left >= right) {
        return 0;
    }

    int mid = left + (right - left) / 2;

    long long counter = 0;
    counter += mergeSortAndCount(arr1, left, mid);
    counter += mergeSortAndCount(arr1, mid + 1, right);
    for (int i = left; i <= mid; ++i) {
        long long a = arr1[i];
        if (a <= 0) {
            continue;
        }
        double root = sqrt((double)a);
        auto it_low = upper_bound(arr1.begin() + mid + 1, arr1.begin() + right + 1, -root);
        auto it_high = lower_bound(arr1.begin() + mid + 1, arr1.begin() + right + 1, root);
        counter += distance(it_low, it_high);
    }
    inplace_merge(arr1.begin() + left, arr1.begin() + mid + 1, arr1.begin() + right + 1);

    return counter;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length1;
    cin >> length1;

    vector<int> arr1(length1);
    for (int i = 0; i < length1; ++i) {
        cin >> arr1[i];
    }

    long long total_inversions = mergeSortAndCount(arr1, 0, length1 - 1);

    cout << total_inversions << endl;

    return 0;
}