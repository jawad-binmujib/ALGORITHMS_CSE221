// Title: The Spice Merchant
// Difficulty: Easy

// Problem Statement:
// A spice merchant has  different spices. For each spice, he knows the total amount available (in kg) and the total price for that amount. He has a bag that can hold a maximum weight .
// Since spices are powders, he can take any fraction of a spice (e.g., 0.5 kg or 0.01 kg).
// Find the maximum total value of spices the merchant can carry in his bag.

// Input:
// First line: Two integers  (number of spices) and  (bag capacity).
// Next  lines: Each contains two integers  (Total Value) and  (Total Weight) for a spice.

// Output:

// A single number representing the maximum value. Print it with 6 decimal places.

// Input:
// 3 50
// 60 10
// 100 20
// 120 30

// Output:
// 240.000000 



#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


struct spice
{   
    int value, weight;

};
bool comparator(spice a, spice b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;

}

double frac_knapsack(int W, vector<spice> &spices){
    sort(spices.begin(), spices.end(), comparator);

    double total_value = 0.0;
    int current_weight = 0;

    for (auto sp : spices){
        if (current_weight + sp.weight <= W){
            current_weight += sp.weight;
            total_value += sp.value;
        }
        else{
            int remaining_weight = W - current_weight;
            total_value += sp.value * ((double)remaining_weight / sp.weight);
            break;
        }
    }
    return total_value;

}

int main(){
    int N, W;
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N >> W)) return 0;
    vector<spice> spices(N);
    for (int i = 0; i < N; i++){
        cin  >> spices[i].value >> spices[i].weight;

    }
    double result = frac_knapsack(W, spices);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}