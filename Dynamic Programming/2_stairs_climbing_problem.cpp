#include<iostream>

using namespace std;

int count_stairs_way(int stairs){
if(stairs<=2){
    return stairs;
}
int left = count_stairs_way(stairs -1);
int right = count_stairs_way(stairs -2);
return left + right;
}
int main(){

int n;
cin>>n;
cout<<count_stairs_way(n);


    return 0;
}