#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int id;
    int mark;
};

bool isResult(const Student& a, const Student& b) {
    if (a.mark > b.mark) {
        return true;
    }
    
    if (a.mark == b.mark) {
        if (a.id < b.id) {
            return true;
        }
    }
    return false;
}

void result() {
    int num1;
    cin >> num1;


    
    vector<Student> students(num1);

    for (int i = 0; i < num1; i++) {
        cin >> students[i].id;
    }
    
    for (int i = 0; i < num1; i++) {
        cin >> students[i].mark;
    }

    int counter = 0;

    for (int i = 0; i < num1 - 1; i++) {
 
        int idx = i; 
        
        for (int j = i + 1; j < num1; j++) {
    
            if (isResult(students[j], students[idx])) {
                idx = j;
            }
        }

        if (idx != i) {

            Student temp = students[i];
            students[i] = students[idx];
            students[idx] = temp;
            
            counter++;
        }
    }

    cout << "Minimum swaps: " << counter << endl;
    for (int i = 0; i < num1; i++) {
        cout << "ID: " << students[i].id << " Mark: " << students[i].mark << endl;
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        result();
    }
    return 0;
}