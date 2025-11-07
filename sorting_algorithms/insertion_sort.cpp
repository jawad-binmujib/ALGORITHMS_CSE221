#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int length;
    cin >> length;
    vector<int> arr1(length);
    for (int i = 0; i < length; i++){
        cin >> arr1[i];
    }
    for (int i = 1;i < length; i++){
        int key = arr1[i];
        int j = i - 1;
        while (j >= 0 && arr1[j] > key)
        {
            arr1[j +1] = arr1[j];
            j--;
        }
        arr1[j + 1] = key;
        
    }

    for (int elem : arr1){
        cout << elem << " ";

    }
    cout << endl;


    return 0;
}