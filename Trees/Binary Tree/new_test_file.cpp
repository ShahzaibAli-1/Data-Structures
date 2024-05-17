#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int value) {
        left = right = nullptr;
        this->data = value;
    }
};

TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }

    if (root->data > key) {
        root->left = insert(root->left, key);
    } else if (root->data < key) {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void levelOrderTraversal(TreeNode * root){
    if (root==nullptr){
        return;
    }
queue<TreeNode*> q;
q.push(root);
while(!q.empty()){
int size = q.size();
for(int i = 0 ;i<size;i++){
    TreeNode * current = q.front();
    q.pop();
    cout<<current->data<<" ";
    if(current->left !=nullptr)
    q.push(current->left);
    else if(current->right!=nullptr)
    q.push(current->right);

}
}
cout<<endl;

}
void calculate_left(TreeNode * leftnode, int height){

}
int max(int h1,int h2){
if(h1>h2){
    return h1;
}

return h2;
}
int calculate_height(TreeNode * node){
if(node==nullptr){
    return 0;
}
int left_height = calculate_height(node->left);
int right_height = calculate_height(node->right);
return max(left_height, right_height)+1;
}
bool checkBalance(TreeNode * node){
    if (node==nullptr){
        return true;
    }
    int leftHeight = calculate_height(node->left);
    int rightHeight = calculate_height(node->right);
    if (abs(leftHeight-rightHeight)>1)
    return false;
    return true;

}
int main() {
    TreeNode* n1 = new TreeNode(4);
    insert(n1, 5);
    insert(n1, 3);
    insert(n1, 2);
    insert(n1, 6);
    inorder(n1);
    cout << endl;
    int height = calculate_height(n1);
    cout<<"The height of tree is:  "<<height<<endl;
    cout<<checkBalance(n1);
    return 0;
}
