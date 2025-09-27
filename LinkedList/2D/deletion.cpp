#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

// Delete node at position (1-based index)
void deleteAtPosition(Node* &head, int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* curr = head;
    int cnt = 1;

    // Traverse to the position
    while (cnt < pos && curr != NULL) {
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) {
        cout << "Position out of range\n";
        return;
    }

    // Case 1: deleting head
    if (curr == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete curr;
        return;
    }

    // Case 2: deleting middle or tail
    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    delete curr;
}

// Print DLL
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    // Create DLL manually: 10 ⇄ 20 ⇄ 30 ⇄ 40
    Node* head = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;

    cout << "Original DLL: ";
    printList(head);

    // Delete head
    deleteAtPosition(head, 1);
    cout << "After deleting head: ";
    printList(head);

    // Delete middle (pos 2 -> 30)
    deleteAtPosition(head, 2);
    cout << "After deleting position 2: ";
    printList(head);

    // Delete tail (last node 40)
    deleteAtPosition(head, 2);
    cout << "After deleting tail: ";
    printList(head);

    return 0;
}
