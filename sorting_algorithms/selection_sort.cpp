#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int selection_sort(vector<int> &arr1, int length){
    for (int i = 0; i < length -1; i++){
        int min_idx = i;
        for (int j = i +1; j < length; j ++){
            if (arr1[j] < arr1[min_idx]){
                min_idx = j;
            }
        }
        swap(arr1[i], arr1[min_idx]);
    }
    return 0;
}
int main(){
    int length;
    cin >> length;
    vector<int> arr1(length);
    for (int i = 0; i < length; i++){
        cin >> arr1[i];
    }
    selection_sort(arr1, length);
    for (int elem : arr1){
        cout << elem << " ";
    }
    cout << endl;
    
    return 0;
}