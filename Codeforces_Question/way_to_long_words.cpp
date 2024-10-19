#include <iostream>
#include <string>

using namespace std;
#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
int main() {
    int n;
    cin >> n; 
    cin.ignore(); 

    for (int i = 0; i < n; ++i) {
        string word;
        getline(cin, word); 

        if (word.length() > 10) {

            cout << word[0] << word.length() - 2 << word[word.length()-1] << endl;
        } else {
            cout << word << endl; 
        }
    }

    return 0;
}
