#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Optimize C++ I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> odd_a, even_a;
    std::vector<int> odd_b, even_b;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        b[i] = a[i];
        // Note: 0-based index 0 is 1st element (odd)
        if (i % 2 == 0) {
            odd_a.push_back(a[i]);
        } else {
            even_a.push_back(a[i]);
        }
    }

    // Create the target sorted array
    std::sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            odd_b.push_back(b[i]);
        } else {
            even_b.push_back(b[i]);
        }
    }

    // Sort the multisets to compare them
    std::sort(odd_a.begin(), odd_a.end());
    std::sort(even_a.begin(), even_a.end());
    std::sort(odd_b.begin(), odd_b.end());
    std::sort(even_b.begin(), even_b.end());

    // 1. Check if sorting is possible
    if (odd_a != odd_b || even_a != even_b) {
        std::cout << "NO\n";
        return 0;
    }

    // 2. Sorting is possible, find the moves.
    std::cout << "YES\n";
    std::vector<std::pair<int, int>> moves;

    // Use 0-based indexing for logic, convert to 1-based for output
    for (int i = 0; i < n; ++i) {
        // We need to place the element b[i] at index i
        int target_val = b[i];
        
        // Find the index j >= i with the correct value and same parity
        int j = -1;
        for (int k = i; k < n; ++k) {
            if (a[k] == target_val && (k % 2 == i % 2)) {
                j = k;
                break;
            }
        }

        // Move the element from j down to i using reverse(k-2, k)
        // which swaps a[k-2] and a[k]
        for (int k = j; k > i; k -= 2) {
            // Add the move (1-based indices)
            moves.push_back({k - 2 + 1, k + 1}); 
            
            // Simulate the swap
            std::swap(a[k - 2], a[k]);
        }
    }

    // Print the moves
    std::cout << moves.size() << "\n";
    for (const auto& p : moves) {
        std::cout << p.first << " " << p.second << "\n";
    }

    return 0;
}