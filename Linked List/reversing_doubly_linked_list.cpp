#include<iostream>
#include<vector>
using namespace std;
struct DNode{
DNode *prev;
DNode * next;
int data;
DNode(int d) : prev(nullptr), next(nullptr), data(d) {}

} ;
struct DoublLL{
DNode *head = nullptr;

void insert(int data){
DNode * newNode = new DNode(data);
if(head==nullptr){
    head = newNode;

}
else{
DNode * current = head;
while(current->next!=nullptr){
current = current->next;
}
current->next = newNode;
newNode->prev = current;
}
}
void show(){
    DNode * current = head;

    while(current!=nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
}
// void reverse(){
//     DNode * current = head;
//     while(current!=nullptr){
//     DNode * last = current->prev;
//     current->prev = current->next;
//     current->next = last;
//     current = current->next;
//     }
// }
void reverse() {
        DNode *current = head;
        DNode *temp = nullptr;

        // Swap prev and next for all nodes
        while (current != nullptr) {
            // Swap prev and next pointers
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            // Move to the next node (which is now the previous node)
            current = current->prev;
        }

        // After the loop, temp will be pointing to the new head node's previous node
        // So we need to adjust head to point to the new front node
        if (temp != nullptr) {
            head = temp->prev;
        }
    }
};

// DNode * adding_two_ll(DNode * head1, DNode * head2){
// DNode * t1 = head1;
// DNode * t2 = head2;
// DNode * DummyNode = new DNode(-1);
// DNode * current= DummyNode;

// int carry = 0;
// while(t1!=nullptr||t2 !=nullptr ){
// int sum = carry;

// if (t1)
// sum = sum + t1->data;
// if (t2)
// sum = sum + t2->data;
// DNode *NewNode = new DNode(sum%10);
// carry = sum/10;
// current->next = NewNode;
// current = current->next;
// if (t1) 
// t1 = t1->next;
// if(t2)
// t2 = t2->next;
// }
// if(carry){
//         DNode* newNode = new DNode(carry);
//         current->next = newNode;
//         newNode->prev = current;
// }
// return DummyNode->next;
// }

DNode* adding_two_ll(DNode* head1, DNode* head2) {
    DNode* t1 = head1;
    DNode* t2 = head2;
    DNode* DummyNode = new DNode(-1);
    DNode* current = DummyNode;

    int carry = 0;
    while (t1 != nullptr || t2 != nullptr) {
        int sum = carry;
        
        if (t1) {
            sum += t1->data;
            t1 = t1->next;
        }
        if (t2) {
            sum += t2->data;
            t2 = t2->next;
        }

        DNode* NewNode = new DNode(sum % 10);
        carry = sum / 10;
        current->next = NewNode;
        NewNode->prev = current;  // Set the previous pointer for the new node
        current = current->next;
    }

    if (carry) {
        DNode* newNode = new DNode(carry);
        current->next = newNode;
        newNode->prev = current;  // Set the previous pointer for the new node
    }

    return DummyNode->next;
}

// void FindEvenOdd(DNode* head){
//     DNode * current = head;
//     int size = 0;
//     while (current->next!=nullptr)
//     {
//         current = current->next;
//         size++;
//     }
//     size++;
//     int *arr = new int [size];
//     for(int i =0 ;i<size;i++){
//         arr[i] = current->data;
//         current = current->next;
//     }
//     for(int i =0 ;i<size;i++){
//         bool check_even = i%2;
//         if(check_even)
//        { arr[i] = current->data;
//         current = current->next;}

//     }
//         for(int i =0 ;i<size;i++){
//         bool check_even = i%2;
//         if(!check_even)
//        { current->data = arr[i];
//         current = current->next;}
//     }
    

// }
void FindEvenOdd(DNode* head) {
    if (head == nullptr) return;

    // Pointers to traverse the list
    DNode* current = head;

    // Vectors to store even and odd indexed nodes
    vector<int> evenData;
    vector<int> oddData;

    int index = 0;
    while (current != nullptr) {
        if (index % 2 == 0) {
            evenData.push_back(current->data);
        } else {
            oddData.push_back(current->data);
        }
        current = current->next;
        index++;
    }

    // Reset the current pointer to head
    current = head;
    index = 0;
    int evenIndex = 0;
    int oddIndex = 0;

    // Rearrange the list to have even indexed nodes followed by odd indexed nodes
    while (current != nullptr) {
        if (index < evenData.size()) {
            current->data = evenData[evenIndex++];
        } else {
            current->data = oddData[oddIndex++];
        }
        current = current->next;
        index++;
    }
}
void show(DNode * head){
DNode * current = head;
while(current!=nullptr){
    cout<<current->data<<" ";
    current = current->next;
}
}

DNode* FindEvenOdd_(DNode * head){
DNode * odd = head;
DNode * even = head->next;
DNode * evenHead = head->next;
while(even!=nullptr && even->next!=nullptr){
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
}
odd->next = evenHead;
return head;
}
void Sort(DNode * head){
DNode * current = head;

int zeros, ones, two;
zeros =0, ones =0, two = 0;
while(current!=nullptr){
if(current->data==0){
    zeros++;
}
if(current->data==1){
    ones++;
}
if(current->data==2){
    two++;
}
current = current->next;
}
current = head;
while(current!=nullptr){
    if(zeros!=0){
        current->data = 0;
        zeros--;
    }
    else if(ones!=0){
        current->data = 1;
        ones--;
    }
    else{
        current->data = 2;
        two--;
    }
current = current->next;
}

}

int main(){
DoublLL l1;
cout<<"Linked list 1: \n";
l1.insert(1);
l1.insert(2);
l1.insert(3);
l1.insert(4);
l1.insert(5);
l1.insert(6);
l1.reverse();
l1.show();
cout<<"\nLinked list 2: \n";
DoublLL l2;
l2.insert(1);
l2.insert(2);
l2.insert(0);
l2.insert(2);
l2.insert(0);
l2.show();
FindEvenOdd_(l1.head);
cout<<"\nThe list after even odd is:\n";
Sort(l2.head);
l2.show();

}
