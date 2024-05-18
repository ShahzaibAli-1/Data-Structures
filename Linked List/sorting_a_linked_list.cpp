#include<iostream>
using namespace std;
struct Node{
    int data;
    Node * next;
    Node(int val) : data(val), next(nullptr) {}

};
Node *conversionLinked_list(int arr[], int size ){
      if(size == 0)
        return nullptr;
Node* head = new Node(arr[0]);


Node *temp = head;

    for (int i = 1; i < size; ++i) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }


return head;
}
int  sum(Node * head){

//using recursion
if (head==NULL){
    return 0;
}
return head->data + sum(head->next);

}
void show(Node * head){
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;


}
int findMax(Node * head){
int maxNum = INT_MIN;
while (head!=NULL){
if (head->data > maxNum){

    maxNum = head->data;
    head=  head->next;
}

}
return maxNum;
}
void sort_linked_list(int arr[],int size){


for (int i = 0 ;i<size-1;i++){
    int min_index = i;
    for (int j = i+1;j<size-1;j++){
        
        if (arr[j]<arr[min_index]){
            min_index = j;
        }
    }
    swap(arr[min_index], arr[i]);
}

}

Node * sort_linked_list(Node * head){
Node * current_node = head;

while (current_node->next != NULL){
Node * min_node = current_node;
Node * runner = current_node->next;
while (runner->next !=NULL){

if (min_node->data > runner-> data){
                min_node = runner;

}
            runner = runner->next;
}
       // Swap values between current and minNode
        int temp = current_node->data;
        current_node->data = min_node->data;

        min_node->data = temp;
        current_node = current_node->next;
        
}
return head;
}

// void sort_bubble(){


// }
int main(){
// int arr [5] = {2,3,4,1,5};
// Node *head= conversionLinked_list(arr, 5);
// show (head);
    int arr[5] = {5, 4, 3, 41, 2};

    // Call the conversion function to convert array to linked list
    Node* head = conversionLinked_list(arr, 5);

    // Display the linked list
    show(head);

cout<<sum(head)<<endl;
cout<<findMax(head)<<endl;
sort_linked_list(arr, 5);
// for(int i = 0 ;i<5;i++){
//     cout <<arr[i]<<" ";
// }
sort_linked_list(head);
show(head);
return 0;
}