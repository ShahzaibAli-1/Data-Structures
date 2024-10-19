#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int w, h, n;
        cin >> w >> h >> n;
        
        int possible_pieces = 1;
        

        while (w % 2 == 0) {
            w /= 2;
            possible_pieces *= 2;  
        }
        

        while (h % 2 == 0) {
            h /= 2;
            possible_pieces *= 2;  
        }
        

        if (possible_pieces >= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
