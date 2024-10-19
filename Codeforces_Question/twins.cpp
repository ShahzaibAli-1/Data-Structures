#include <iostream>
#include <algorithm>  
#include<vector>
using namespace std;
#pragma GCC optimize("Ofast")
static auto _ = [](){ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();

int main(){
int n;
cin>>n;
int num;
vector<int> v;
int sum= 0;
while(n--){
    int num;
    cin>>num;
    v.push_back(num);
    sum+=num;
}
sort(v.begin(), v.end(), greater<int>());
int total_candies = 0;
int sum_2 = 0;
while(sum_2<=sum/2){
    sum_2 += v[total_candies];
    total_candies+=1;
    
}
cout<<total_candies;
    return 0;
}
