#include<iostream>
using namespace std;
class Node{
int data;
Node* Next; 
};
//This is Question for removing the nth node from the last in reverse order
// for case if n = 2 than in case if there are 5 nodes than node 4 will be removed in case if n=3 than node 3 will be removed as nodes are being removed in reverse order
void Traverse(Node * head){

int counter = 0;

    while(head!=NULL){


        cout<<"data at node "<<counter<<" is: "<< head->data<<endl;
        head = head->Next;
        counter++;
    }
}
Node* Reverse_linked_list(Node * head, int n){
while(head->Next!=NULL){
    
}


}
int main(){


return 0;
}