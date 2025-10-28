#include <iostream>
#include <vector>
using namespace std; 

int main() {
    int num1;
    cin >> num1;

    vector<int> arr(num1);

    for (int i = 0; i < num1; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num1 - 1; j++) {
            

            bool equal_parity = ((arr[j] % 2) == (arr[j + 1] % 2));
            
            if (equal_parity) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    for (int i = 0; i < num1; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}  