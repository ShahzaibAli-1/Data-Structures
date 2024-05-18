#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* selectionSort(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* current = head;
    while (current) {
        ListNode* minNode = current;
        ListNode* runner = current->next;
        while (runner) {
            if (runner->val < minNode->val)
                minNode = runner;
            runner = runner->next;
        }

        // Swap values between current and minNode
        int temp = current->val;
        current->val = minNode->val;
        minNode->val = temp;

        current = current->next;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 3 -> 1 -> 4 -> 2
    ListNode* head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(2);

    cout << "Original list: ";
    printList(head);

    // Sort the linked list using selection sort
    head = selectionSort(head);

    cout << "Sorted list: ";
    printList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
