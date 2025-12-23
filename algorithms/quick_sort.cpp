#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partition(vector<int> &arr1, int low, int high){

    int pivot = arr1[high];
    int i = low - 1;
    for (int j = low ; j <= high ; j ++){
        if (arr1[j] < pivot){
            i ++;
            swap(arr1[i], arr1[j]);
        }
    }
    swap(arr1[i +1], arr1[high]);
    return i +1;
}

void Quick_sort(vector<int>&arr1, int low, int high){
    if (low < high ){
        int pi = partition(arr1, low, high);
        Quick_sort(arr1, low, pi  -1);
        Quick_sort(arr1, pi + 1, high);
    }
}

int main(){
    int length;
    cin >> length;
    vector<int> arr1(length);
    for (int i = 0 ; i < length; i ++){
        cin >> arr1[i];
    }
    Quick_sort(arr1, 0, length - 1);
    for (int elem : arr1){
        cout << elem <<" ";
    }
    return 0;
}