#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Train {
    string trainName;
    string destination;
    string time;
    int idx; 
};

bool isResult(const Train& a, const Train& b) {

    if (a.trainName != b.trainName) {
        return a.trainName < b.trainName;
    }

    if (a.time != b.time) {
        return a.time > b.time;
    }
    return a.idx < b.idx;
}

int main() {

    int num1;
    cin >> num1;
    vector<Train> schedule(num1);
    string str1; 

    for (int i = 0; i < num1; i++) {
        cin >> schedule[i].trainName 
            >> str1 
            >> str1 
            >> str1 
            >> schedule[i].destination 
            >> str1 
            >> schedule[i].time;

        schedule[i].idx = i;
    }
    for (int i = 0; i < num1 - 1; i++) {
        for (int j = 0; j < num1 - i - 1; j++) {
            if (isResult(schedule[j + 1], schedule[j])) {
                Train temp = schedule[j];
                schedule[j] = schedule[j + 1];
                schedule[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < num1; i++) {
        cout << schedule[i].trainName << " will departure for "
             << schedule[i].destination << " at " << schedule[i].time << "\n";
    }

    return 0;
}