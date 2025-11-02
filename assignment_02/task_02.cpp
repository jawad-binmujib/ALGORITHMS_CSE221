#include <iostream>
#include <vector>
#include <cmath>
#include <climits>   
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int length1, length2;
    long long targeted_sum; 

    cin >> length1 >> length2 >> targeted_sum;
    vector<long long> arr1(length1);
    vector<long long> arr2(length2);

    for (int i = 0; i < length1; i++) {
        cin >> arr1[i];
    }

    for (int j = 0; j < length2; j++) {
        cin >> arr2[j];
    }

    int left_pointer = 0;    
    int right_pointer = length2 - 1; 
    long long min = LLONG_MAX; 
    int i = 0; 
    int j = 0;

    while (left_pointer < length1 && right_pointer >= 0) {
        long long sum = arr1[left_pointer] + arr2[right_pointer];
        long long diff = std::abs(sum - targeted_sum);

        if (diff < min) {
            min = diff;
            i = left_pointer;
            j = right_pointer;
        }

        if (min == 0) {
            break;
        }
        if (sum < targeted_sum) {
            left_pointer+=1;
        }
        else {
            right_pointer-=1;
        }
    }

    cout << (i + 1) << " " << (j + 1) << endl;
    return 0;
}