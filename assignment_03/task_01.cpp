#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& arr1, int left, int mid, int right) {

    int length1 = mid - left + 1;
    int length2 = right - mid;
    vector<int> left_arr(length1);
    vector<int> right_arr(length2);


    for (int i = 0; i < length1; i++)
        left_arr[i] = arr1[left + i];
    for (int j = 0; j < length2; j++)
        right_arr[j] = arr1[mid + 1 + j];


    int i = 0; 
    int j = 0; 
    int k = left; 

    long long inverse_count = 0;

    while (i < length1 && j < length2) {
        if (left_arr[i] <= right_arr[j]) {
            arr1[k] = left_arr[i];
            i++;
        } else {
            arr1[k] = right_arr[j];
            j++;
            inverse_count += (length1 - i);
        }
        k++;
    }


    while (i < length1) {
        arr1[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < length2) {
        arr1[k] = right_arr[j];
        j++;
        k++;
    }

    return inverse_count;
}

long long mergeSort(vector<int>& arr1, int left, int right) {
    long long inverse_count = 0;
    if (left < right) {

        int mid = left + (right - left) / 2;

        inverse_count += mergeSort(arr1, left, mid);
        inverse_count += mergeSort(arr1, mid + 1, right);
        inverse_count += merge(arr1, left, mid, right);
    }
    return inverse_count;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length3;
    cin >> length3;

    vector<int> arr1(length3);
    for (int i = 0; i < length3; i++) {
        cin >> arr1[i];
    }

    long long total_inversions = mergeSort(arr1, 0, length3 - 1);
    cout << total_inversions << endl;

    for (int i = 0; i < length3; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}