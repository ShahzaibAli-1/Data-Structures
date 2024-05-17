#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
    Node(int val):  data(val), left(NULL), right(NULL){}
};
Node* creating_tree(Node * node){
int data;
cout<<"Enter the data: ";
cin>>data;
node = new Node(data);
if (data==-1){
    return NULL;
}

cout<<"Enter the left value of "<<data<<": ";
node->left = creating_tree(node->left);
cout<<"Enter the right value of "<<data<<": ";
node->right = creating_tree(node->right);
return node;

}
int height(Node * node){

if (node==NULL){
    return 0;
}
int left = height(node->left);
int right = height(node->right);
int ans = max(left, right) + 1;
return ans;
}
int main(){

Node * root = NULL;
root = creating_tree(root);
cout<<"Max height of node in tree is: "<<height(root)<<" ";
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
return 0;
}