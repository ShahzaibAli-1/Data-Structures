#include<iostream>
#include<vector>

using namespace std;
int f(int n, vector<int> &dp){
if(n<=2){
    return n;
}
if(dp[n]!=-1) return dp[n];
return dp[n] =  f(n-1, dp) + f(n-2, dp);

}


int main(){
    int size;
    cin>>size;
    // vector<int> dp(size+1, -1);
    // cout<<f(size, dp);
    //Changing it in loop format
    int prev = 1;
    int prev2 = 0;
    int current = 0;
    for(int i =1;i<=size;i++){
        current = prev2+ prev;
        prev2 = prev;
        prev= current;
    }
    cout<<current<<endl;
    return 0;
}