#include<iostream>
#include<string>
using namespace std;
int main(){
    int num1;
    cin >> num1;
    for (int i = 1; i <= num1; i ++){
        double num2,num3;
        char op;
        cin >> num2 >> num3;
        cin >> op;
        if (op == '+'){
            cout << num2 + num3 << endl;
        }
        else if (op == '-'){
            cout << num2 - num3 << endl;
        }
        else if (op == '*'){
            cout << num2 * num3 << endl;
        }
        else{
            cout << num2 / num3 << endl;
        }

    }
    return 0;
}