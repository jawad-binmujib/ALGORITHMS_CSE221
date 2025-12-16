#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void solve(){
    int length;
    cin >> length;
    int max_val = 0;
    vector<int> arr1(length);
    for (int i =0; i < length; i++){
        int elem;
        cin >> elem;
        arr1[i] = elem;
        if (elem > max_val) max_val = elem;
    }
    cout << max_val << endl;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int t_cases;
    cin >> t_cases;
    while(t_cases--){
        solve();
    }

}