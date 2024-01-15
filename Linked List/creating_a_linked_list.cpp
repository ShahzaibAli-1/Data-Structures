#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node(int value) :data(value), next(nullptr){};
};
class LinkedList{
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void calculatesum(){
        Node * current = head;
        int sum = 0;
        while (current !=nullptr)
        {
            sum+= current->data;
            current = current->next;
        }
        cout<<"The sum of data in linked list is: "<<sum<<endl;
    }
};
int main(){
    LinkedList myLinkedList;
    myLinkedList.append(1);
    myLinkedList.append(2);
    myLinkedList.append(3);
    myLinkedList.printList();
    myLinkedList.calculatesum();
    return 0;
}