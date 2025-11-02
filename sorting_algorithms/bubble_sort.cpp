#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

    int length;
    cin >> length;
    vector<int>arr1(length);
    for (int i = 0; i < length; i++){
        cin >> arr1[i];
    }

    for (int i = 0; i < length - 1; i++){
        for (int j = 0; j < length - 1; j ++){
            if (arr1[j] > arr1[j + 1]){
                swap(arr1[j], arr1[j + 1]);
            }
        }
    }
    for (int i : arr1){
        cout << i << " " ;

    }
    return 0;
}