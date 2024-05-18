#include<iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};

Node  *create_ll(Node * head, int size){
Node * current = new Node;
current = head;

for (int i = 0;i<size;i++){
int data;
cout<<"Enter the value of node #"<<i+1<<" : ";
cin>>data;
if (i==0){
    head->data = data;
}
else{Node * node =  new Node;
node->data = data;
node->next = nullptr;
current->next = node;

current = current->next;}

}
return head;

}

void traverse(Node *head){
    cout<<"\nLinked list is in following format: "<<endl;
    Node * temp = head;

while(temp!=NULL){
    if(temp->next!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;}
    else{
    cout<<temp->data;
    break;
    }

}
}
int lsearch(Node * head, int data){
Node * prev = head;
Node * next = head->next;
int counter = 0;
while(prev!=NULL){
counter++;
if (prev->data == data){
return counter;
}
prev = prev->next;
}
return -1;

}
Node * insertAThead(Node * head, int value){
Node * temp = new Node;
temp->next = head;
temp->data = value;
return temp;

}

void insertAttail(Node* head, int value){
Node * node= new Node;
Node * temp = new Node;
temp = head;
while (temp->next!=NULL){
temp = temp->next;
}
node->data = value;
node->next = nullptr;
temp->next = node;

}
void InsertInbetween_value(Node * head, int key){
Node * temp = new Node;
temp = head;

while(head->next !=NULL){

}

}
int find_middle_element(Node * head){
Node * temp = new Node;
temp = head;
int counter = 0;
while (temp!=NULL){

    temp= temp->next;
    counter++;
}
counter/=2;
for(int i = 0;i<counter;i++){
    head = head->next;
}
return head->data;
}
void insertAtloc(Node * head, int value, int loc){

Node * prev = new Node;
prev = head;
Node * next = new Node;
next = head->next;
Node * temp = new Node;
if (head==NULL){
    head = temp;
    temp->data = value;
    return;
}
for (int i = 1;i<loc;i++){
    prev = next;
    next = next->next;

}
temp->data = value;
prev->next = temp;
temp->next = next;
cout <<"Not found"<<endl;
}
void delete_head(Node* head){
Node * node = new Node;
node = head;
head = head->next;
delete node;
}
void search_recursively(Node * head, int value){
    
if (head->next==NULL || head->data == value){
    if (head->data==value){
        cout<<"Value found"<<endl;
    }
    else {
        cout<<"Value not found"<<endl;
    }
    return;
}
search_recursively(head->next, value);
}
void search( Node * head, int value){
    Node * temp = new Node;

    while (temp->data == value){
        temp = temp->next;
        
    }
    
}
void odd_and_even_list(Node * head){
Node * temp = head;
Node * current = head;
Node * node = new Node;
while(temp!=NULL){
cout<<temp->data<<" ";    
temp = temp->next->next;
current = current->next;

}
return;
}
   Node* oddEvenList(Node* head) {
        if(head == NULL || head->next == NULL) return head;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = head->next;

        while(even!=NULL && even->next!=NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }

    Node * reverseLL(Node * head){
        Node * temp = head;
        Node * prev = NULL;
        while(temp!=NULL){
            Node * front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

void remove_duplicates(Node *head) {
    if (head == nullptr) // Check if the list is empty
        return;

    Node *current = head;
    while (current != nullptr && current->next != nullptr) {
        Node *next_node = current;

        // Inner loop to check for duplicates
        while (next_node->next != nullptr) {
            if (current->data == next_node->next->data) {
                Node *duplicate = next_node->next;
                next_node->next = next_node->next->next;
                delete duplicate;
            } else {
                next_node = next_node->next;
            }
        }
        current = current->next; // Move to the next node
    }
}

int main(){

Node * n1 = new Node;

int size;
cout<<"Enter the size of linked list: ";
cin>>size;
create_ll(n1, size);
traverse(n1);
n1 = insertAThead(n1, 9);
traverse(n1);
insertAttail(n1,10);
traverse(n1);
// if(lsearch(n1,10)==-1){
//     cout<<"\nNot found"<<endl;
// }
// else
// cout<<"\nNode # "<<lsearch(n1, 3)<<" contains requried number: "<<endl;
// insertAtloc(n1, 11,3);
// traverse(n1);
cout<<"\nmiddle element: "<<find_middle_element(n1)<<" ";
// search_recursively(n1,10);
// oddEvenList(n1);
// traverse(n1);
// Node * n2 = new Node;
// n2 = reverseLL(n1);
// traverse(n2);
remove_duplicates(n1);
traverse(n1);
return 0;
}