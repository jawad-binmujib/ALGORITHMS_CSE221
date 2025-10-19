#include<iostream>
using namespace std;
int main(){
    int test_cases,sum;
    cin >> test_cases;
    for (int i = 1; i <= test_cases; i++){
        long long num1;
        cin >> num1;
        long long sum = 0;
        sum += (num1*(num1 + 1)) / 2;
        cout << sum << endl; 
    }


    return 0;
}