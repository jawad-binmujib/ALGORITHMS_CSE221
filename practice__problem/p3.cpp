// check if the array is palindrome or not

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases;i ++){
        int length;
        cin >> length;
        vector<int> arr1(length);
        for (int i = 0 ; i< length; i++){
            int elem;
            cin >> elem;
            arr1[i] = elem;
        }
        bool isPalindrome = true;
        for (int i = 0; i < length / 2; i ++){
            if (arr1[i] != arr1[length - i - 1]){
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome) {
            cout << "Palindrome" << endl;
        } else {
            cout << "Not Palindrome" << endl;
        }
    }
    
}
