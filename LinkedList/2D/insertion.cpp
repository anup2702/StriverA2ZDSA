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

// Insert at head
void insertAtHead(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Insert at tail
void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at position (1-based index)
void insertAtPosition(Node* &head, int pos, int data) {
    if (pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position out of range\n";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
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
    Node* head = NULL;

    // Insertion at head
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    printList(head); // 10 20

    // Insertion at tail
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    printList(head); // 10 20 30 40

    // Insertion at position
    insertAtPosition(head, 3, 25); 
    printList(head); // 10 20 25 30 40

    return 0;
}
