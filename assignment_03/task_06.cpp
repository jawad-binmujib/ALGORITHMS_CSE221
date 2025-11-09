#include <iostream>
#include <vector>
using namespace std;

void findOptimalOrder(const vector<int>& arr1, int left, int right) {
    if (left > right) {
        return;
    }

    int mid = left + (right - left) / 2;
    cout << arr1[mid] << " ";
    findOptimalOrder(arr1, left, mid - 1);
    findOptimalOrder(arr1, mid + 1, right);
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

    findOptimalOrder(arr1, 0, length1 - 1);
    cout << endl;
    
    return 0;
}