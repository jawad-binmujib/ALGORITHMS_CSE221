#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length;
    cin >> length;
    vector<int> arr1(length);
    for (int i = 0; i < length; i++) {
        cin >> arr1[i];
    }

    int length2;
    cin >> length2;
    vector<int> arr2(length2);
    for (int i = 0; i < length2; i++) {
        cin >> arr2[i];
    }
    vector<int> merged_arr(length + length2);
    int i = 0; 
    int j = 0; 
    int k = 0; 
    while (i < length && j < length2) {
        if (arr1[i] <= arr2[j]) {
            merged_arr[k] = arr1[i];
            i++; 
        } 
        else {
            merged_arr[k] = arr2[j];
            j++; 
        }
        k++;
    }
    while (i < length) {
        merged_arr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < length2) {
        merged_arr[k] = arr2[j];
        j++;
        k++;
    }

    for (int idx = 0; idx < length + length2; idx++) {
        cout << merged_arr[idx] << " ";
    }
    cout << endl;
    return 0;
}