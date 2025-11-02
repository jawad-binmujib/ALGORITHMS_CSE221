#include <iostream>
#include <vector>
#include <unordered_map> 
#include <algorithm> 
using namespace std;   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int length, k;
    cin >> length >> k;
    vector<int> arr1(length);
    for (int i = 0; i < length; i++) {
        cin >> arr1[i];
    }

    int max_length = 0; 
    int left_pointer = 0;    
    unordered_map<int, int> mapped;
    for (int i = 0; i < length; i++) {
        mapped[arr1[i]]+=1;
        while (mapped.size() > k) {
            int removed_elem = arr1[left_pointer];
            mapped[removed_elem]-=1;
            if (mapped[removed_elem] == 0) {
                mapped.erase(removed_elem);
            }

            left_pointer+=1;
        }
        max_length = max(max_length, i - left_pointer + 1);
    }
    cout << max_length << endl;
    return 0;
}