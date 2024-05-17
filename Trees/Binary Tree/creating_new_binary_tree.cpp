#include<iostream>
#include<queue>
using namespace std;
struct Node{

int data;
Node * left;
Node * right;
Node(int d){
    this->data = d;
    left = NULL;
    right = NULL;
}
};
Node * buildTree(Node * root){
int data;
cout<<"Enter the data: ";
cin>>data;
root = new Node(data);
if (data ==-1){
    return NULL;
}
cout<<"Enter the data for insertion in left of "<<data<<endl;
root->left = buildTree(root->left);
cout<<"Enter the data for inserting in right of "<<data<<endl;
root->right = buildTree(root->right);
return root;
}
//BFS
void levelOrderTraversal(Node * root){
//BFS 
queue<Node*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
Node * temp = q.front();

q.pop();

if (temp ==NULL){
cout<<endl;
if (!q.empty()){
    q.push(NULL);
}

}

else {
    cout<<temp->data<<" ";
    if (temp->left){
    q.push(temp->left);

}
if (temp->right)
    {q.push(temp->right);}
}


}
}
void inordertraversal(Node * root){
if (root==NULL){
    return;
}
//LNR
inordertraversal(root->left);
cout<<root->data<<" ";
inordertraversal(root->right);

}

void preorder(Node * root){
    //DFS 
if (root==NULL){
    return;
}
//NRL
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);

}
void postorder(Node * root){
    if (root ==NULL){
        return;
    }
    //LRN Left right (print)
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void total_nodes(Node * root, int &counter){
if (root==NULL){
    return ;
}
total_nodes(root->left, counter);
if (root->left == NULL && root->right==NULL){
    counter++;
}
total_nodes(root->right, counter);
}
int main(){
Node *root = NULL;
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
root = buildTree(root);
cout<<"Printing level order traversal: \n";
levelOrderTraversal(root);

cout<<"Printing inorder traversal: \n";
inordertraversal(root);

cout<<"Printing preorder traversal: \n";
preorder(root);
cout<<"Printing postorder traversal: \n";
postorder(root);
cout<<"\nTotal Nodes present are: \n";
int counter_value = 0;
total_nodes(root,counter_value);
cout<<counter_value<<"\n";
return 0;
}