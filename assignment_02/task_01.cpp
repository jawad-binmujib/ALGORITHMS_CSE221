#include<iostream>
#include<vector>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int length ;
    long long sum;
    cin >> length >> sum;
    vector<long long>arr(length);
    for (int i = 0; i < length; i++){
        cin >> arr[i];

    }
    int left_pointer = 0;
    int right_pointer = length -1 ;

    bool result = false;
    while (left_pointer < right_pointer){
        long long current_sum = arr[left_pointer] + arr[right_pointer];
        if (current_sum == sum){
            cout << (left_pointer + 1) << " " << (right_pointer + 1) << endl;
            result = true;
            break;
        }
        else if (current_sum < sum){
            left_pointer++;
        }
        else{
            right_pointer--;
        }
    }

    if (!result) {
        cout << "-1" << endl;
    }

    return 0;
}
