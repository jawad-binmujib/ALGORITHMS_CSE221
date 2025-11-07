#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(vector<int> &arr1, int left, int mid, int right){
    int length1 = mid - left + 1; 
    int length2 = right - mid;
    vector<int>left_arr(length1);
    vector<int>right_arr(length2);

    for (int i = 0 ; i < length1; i ++){
        left_arr[i] = arr1[left + i];
    }
    for (int j = 0 ; j < length2 ; j ++){
        right_arr[j] = arr1[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < length1 && j < length2){
        if (left_arr[i] <= right_arr[j]){
            arr1[k] = left_arr[i];
            i++;
        }
        else{
            arr1[k] = right_arr[j];
            j ++;
        }
        k ++;
    } 
    
    while (i < length1){
        arr1[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < length2){
        arr1[k] = right_arr[j];
        j ++;
        k ++;
    }
}

int merge_sort(vector<int> &arr1, int left, int right){
    if (left >= right){
        return 0;
    }
    int mid = ((right - left) / 2) + left;
    merge_sort(arr1, left, mid);
    merge_sort(arr1, mid + 1, right);
    merge(arr1, left, mid, right);
    return 0;
}

int main(){
    int length;
    cin >> length;
    vector<int>arr1(length);
    for (int i = 0; i < length; i++){
        cin >> arr1[i];
    }
    merge_sort(arr1, 0, length -1);;
    for (int elem : arr1){
        cout << elem << " ";
    }

    return 0;
}
