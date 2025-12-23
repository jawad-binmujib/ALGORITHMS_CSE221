#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void insertion_sort(vector<int> &arr1, int length){
    for (int i = 1; i < length; i ++){
        int key = arr1[i];
        int j = i;
        while (j > 0 && arr1[j -1]> key){
            swap(arr1[j], arr1[j-1]);
            j--;
        }
    }
}
int main(){
    int length;
    cin >> length;
    vector<int> arr1(length);
    for (int i = 0; i < length; i++){
        cin >> arr1[i];
    }
    insertion_sort(arr1, length);
    for (int elem : arr1){
        cout << elem << " "; 
    }
}