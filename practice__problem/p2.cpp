// Problem Statement: Given an array and a key, find the number of times the key occurs in the array.

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int test_cases;
    cin  >> test_cases;

    for (int i = 0; i < test_cases; i++){
        int length , key;
        cin >> length >> key;
        vector<int> arr1(length);
        int counter = 0;
        for (int i = 0; i < length; i++){
            int elem;
            cin >> elem;
            arr1[i] = elem;
        }
        for (int i = 0; i < length; i ++){
            if (arr1[i] == key){
                counter ++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}