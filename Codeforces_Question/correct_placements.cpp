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
        
        vector<pair<pair<int, int>, int>> friends;
        
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            friends.push_back({{min(h, w), max(h, w)}, i + 1});
        }
        
        sort(friends.begin(), friends.end());
        
        vector<int> result(n, -1);
        int min_friend_index = -1;
        int min_w = 1e9 + 1;
        
        for (int i = 0; i < n; i++) {
            int min_h = friends[i].first.first;
            int max_w = friends[i].first.second;
            int index = friends[i].second;
            
            if (min_w < max_w) {
                result[index - 1] = min_friend_index;
            }
            
            if (max_w < min_w) {
                min_w = max_w;
                min_friend_index = index;
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
