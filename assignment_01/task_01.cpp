#include<iostream>
using namespace std;
int main(){
    int num1;
    cin >> num1;
    for (int i = 1; i <= num1; i ++){
        int num2;
        cin >> num2;
        if (num2 % 2 == 0){
            cout << num2 << " is an Even number." << endl;
        }
        else{
            cout << num2 << " is an Odd number." << endl;
        }
    }
    return 0;
}