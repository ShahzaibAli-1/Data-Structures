#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
int main() {
    int t;
    cin >> t;    
    while (t--) {
        int n;
        cin >> n; 
        
        vector<int> a(n + 1); 
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        
        vector<long long> dp(n + 1, 0); 
        long long max_score = 0; 
        

        for (int i = n; i >= 1; --i) {
            dp[i] = a[i];             

            if (i + a[i] <= n) {
                dp[i] += dp[i + a[i]]; 
            }
            

            max_score = max(max_score, dp[i]);
        }
        
        cout << max_score << endl; 
    }
    
    return 0;
}
