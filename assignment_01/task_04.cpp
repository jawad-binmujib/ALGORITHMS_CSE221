
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int test_cases; 
    cin >> test_cases;
    for (int i = 0 ; i < test_cases; i++) {
        int length; 
        cin >> length;
        vector<int> arr1(length);

        for (int i = 0; i < length; i ++) {
            int elem;
            cin >> elem;
            arr1[i] = elem;
        }
        bool isAssend = true;
        for (int i = 0; i < length - 1; i ++) {
            if (arr1[i] > arr1[i + 1]){
                isAssend = false;
                break;
            }
        }

        if (isAssend) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
