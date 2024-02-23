#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* insertBeforeHead(ListNode* head, int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;

    int limit, value;
    
    cout << "Enter the limit for the number of elements to insert: ";
    cin >> limit;
    for (int i = 0; i < limit; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        head = insertBeforeHead(head, value);
    }

    cout << "List after inserting "<< limit <<" values: ";
    printList(head);

    return 0;
}
