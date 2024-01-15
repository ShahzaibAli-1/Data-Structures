#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

void Traversal(Node *ptr)
{
    int counter = 1;

    while (ptr != NULL)
    {

        cout << "Value at node " << counter << " is: " << ptr->data << endl;
        counter += 1;
        ptr = ptr->next;
    }
}
void AddAtHead(Node *ptr){

}
int main()
{

    Node *first = new (Node);
    Node *Second = new (Node);
    Node *Third = new (Node);
    Node *Fourth = new (Node);
    Node *Firsht = new(Node);
    
    
    Firsht->data = 33;
    Firsht->next = first;
    

    first->data = 11;
    first->next = Second;

    Second->data = 22;
    Second->next = Third;

    Third->data = 19;
    Third->next = Fourth;

    Fourth->data = 23;
    Fourth->next = NULL;
    Traversal(Firsht);
    return 0;
}