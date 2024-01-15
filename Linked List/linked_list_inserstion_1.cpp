#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * Next;

};

void Traverse(Node  *ptr){

int counter = 0;
while(ptr!=NULL){

cout<<"The Data at node "<<counter<<" is: "<<ptr->data<<endl;
ptr = ptr->Next;
counter +=1;
}
}

Node InsertAtHead(Node * head, int data){

Node * NewNode = new Node;
NewNode->data = data;
NewNode->Next = head;
return *NewNode;

}

void InsertAttail(Node *ptr, int data){
Node *EndNode = new Node;
EndNode->data = data;

while(ptr->Next!=NULL){

ptr = ptr->Next;

}
ptr->Next = EndNode;
EndNode->Next  = nullptr;

}

// void InsertinBetween(Node * ptr, int data, int index){
// Node * node = new Node;
// node->data = data;
// int counter=  0;
// while( counter!=index-1){
// ptr = ptr->Next;
// counter +=1;
// }
// node->Next = ptr;
// ptr->Next = node;
// }

void InsertAtIndex(Node *ptr, int data, int index){
    Node *node = new Node;
    node->data = data;
    int counter = 0;

    while (counter != index - 1 && ptr != nullptr) {
        ptr = ptr->Next;
        counter += 1;
    }

    if (ptr == nullptr) {
        cout << "Index out of bounds." << endl;
        delete node;  // Free the allocated memory for the new node
        return;
    }

    node->Next = ptr->Next;
    ptr->Next = node;
}

void InsertInNode( Node * previousnode , int data )
{

Node *node = new Node;
node->data = data;
node->Next = previousnode->Next;
previousnode->Next = node;

}
int main(){
    Node *first = new Node;
    Node *second = new Node ;
    Node * third = new Node;
    Node * fourth = new Node;
    Node * new_node = new Node;
    Node * between_node = new Node;
    first->data  = 10;
    first->Next = second;

    second->data = 12;
    second->Next = third;

    third->data = 13;
    third->Next = fourth;

    fourth->data = 16;
    fourth->Next = nullptr;
    cout<<"\nTraversing without new node:"<<endl;
    
    Traverse(first);

    *new_node = InsertAtHead(first, 19);
    cout<<"\nTraversing with new node insertion at head : "<<endl;
    Traverse(new_node);

    InsertAttail(new_node, 39);
    cout<<"\nTraversing with new node insertion at tail : "<<endl;
    Traverse(new_node);


    cout<<"\nTraversing with new node insertion at given index 3 : "<<endl;

    InsertAtIndex(new_node, 50,4);


    Traverse(new_node);

    cout<<"\nTraversing with new node insertion at given node : "<<endl;
    InsertInNode(third, 44);


    Traverse(new_node);


    return 0;
}