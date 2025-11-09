//Find the Maximum Element in an Array

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int test_cases;
    cin >> test_cases;
    int max_elem = INT_MIN;
    for (int i = 0 ; i < test_cases; i ++){
        int length;
        cin >> length;
        vector<int> arr1(length);
        for (int i = 0; i < length; i ++){
            int elem;
            cin >> elem;
            arr1[i] = elem;
        }
        for (int  i = 0; i < length;  i++){
            if (arr1[i] > max_elem){
                max_elem = arr1[i];
            }
        }
        cout << max_elem << endl;

    }

}