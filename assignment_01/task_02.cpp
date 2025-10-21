#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
    int num1;
    cin >> num1;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= num1; i ++){
        double num2,num3;
        string word;
        char op;
        cin >> word >> num2  >> op >> num3;
        
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