#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node();
    Node(int data);
};

class LinkedList {
    Node *head;

public:
    LinkedList();

    void insertAtHead(int data);

    // Complexity: O(n^2)
    void insertionSort();

    // Complexity: O(n^2) worst case, O(n) for nearly-sorted input.
    // Uses a sortedTail pointer to short-circuit the inner scan when the
    // next element is already >= the last sorted element.
    void optimizedInsertionSort();

    void print();
};
