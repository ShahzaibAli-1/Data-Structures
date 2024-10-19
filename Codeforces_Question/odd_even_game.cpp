#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        

        sort(a.begin(), a.end(), greater<int>());
        
        long long alice_score = 0, bob_score = 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { 
                if (a[i] % 2 == 0) { 
                    alice_score += a[i];
                }
            } else { 
                if (a[i] % 2 == 1) { 
                    bob_score += a[i];
                }
            }
        }
        
        if (alice_score > bob_score) {
            cout << "Alice" << endl;
        } else if (bob_score > alice_score) {
            cout << "Bob" << endl;
        } else {
            cout << "Tie" << endl;
        }
    }
    
    return 0;
}
