#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();

int main(){

int test_cases;
int candies;
int candy;
cin>>test_cases;
for(int i = 0;i<test_cases ;i++){
    cin>>candies;
    int sum = 0;
    if(candies%2==0)
    {for(int j = 0 ;j<candies;j++){
        cin>>candy;
        sum+=candy;
    }
    if(sum%2==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    }

    else{
        
    for(int j = 0 ;j<candies;j++){
            cin>>candy;

        }
            cout<<"NO\n";
    }

    
}
    return 0;
}