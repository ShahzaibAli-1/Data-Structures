#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t;
    
    while (t--) {
        int n; 
        cin >> n;
        
        int ones = 0, twos = 0; 
        
        for (int i = 0; i < n; i++) {
            int candy;
            cin >> candy;
            if (candy == 1) {
                ones++;
            } else {
                twos++;
            }
        }
        

        int total_weight = ones + 2 * twos;
        if (total_weight % 2 != 0) {
            cout << "NO\n";
        } else {

            int half_weight = total_weight / 2;
            

            if (half_weight % 2 == 0 || (ones >= 2)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}
