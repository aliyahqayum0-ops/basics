#include "linked_list.h"

Node::Node() {
    data = 0;
    next = NULL;
}

Node::Node(int data) {
    this->data = data;
    this->next = NULL;
}

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertAtHead(int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertionSort() {
    if (!head || !head->next) return;

    Node *dummy = new Node(0);
    Node *curr = head;

    while (curr != nullptr) {
        Node *nextNode = curr->next;

        Node *prev = dummy;
        while (prev->next != nullptr && prev->next->data < curr->data) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;
        curr = nextNode;
    }

    head = dummy->next;
    delete dummy;
}

void LinkedList::optimizedInsertionSort() {
    if (!head || !head->next) return;

    Node *dummy = new Node(0);
    dummy->next = nullptr;
    Node *sortedTail = dummy;
    Node *curr = head;

    while (curr != nullptr) {
        Node *nextNode = curr->next;

        if (sortedTail->data <= curr->data) {
            sortedTail->next = curr;
            curr->next = nullptr;
            sortedTail = curr;
        } else {
            Node *prev = dummy;
            while (prev->next != nullptr && prev->next->data < curr->data) {
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
        }

        curr = nextNode;
    }

    head = dummy->next;
    delete dummy;
}

void LinkedList::print() {
    Node *temp = head;
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
