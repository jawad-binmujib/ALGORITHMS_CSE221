#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bubble_sort(vector<int> &arr1, int length){
    for (int i =0; i < length; i++){
        for (int j = 0 ; j < length; j++ ){
            if (arr1[j] > arr1[j +1]){
                swap(arr1[j], arr1[j+1]);
            }
        }
    }
    return 0;
}
int main(){
    int length;
    cin >> length;
    vector<int> arr1(length);
    for (int i =0; i < length; i ++){
        cin >> arr1[i];
    }
    bubble_sort(arr1, length);
    for (int elem  : arr1){
        cout << elem << " ";
    }

    return 0;
}