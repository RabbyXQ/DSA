#include <iostream>

using namespace std;

template <typename A>
class Node{
public:
    A data;
    Node *nextPtr;
    Node(A data)
    {
        this->data = data;
        nextPtr = nullptr;
    }
};

template <typename B>
class LinkedList{
private:
    Node<B> *head;
public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insertion at the end of the list
    void addItem(B data)
    {
        if (head == nullptr) {
            head = new Node<B>(data);
        } else {
            Node<B> *current = head;
            while (current->nextPtr != nullptr) {
                current = current->nextPtr;
            }
            current->nextPtr = new Node<B>(data);
        }
    }

    // Deletion of a node with a given data value
    void deleteItem(B data)
    {
        if (head == nullptr) {
            return; // List is empty
        }

        if (head->data == data) {
            Node<B> *temp = head;
            head = head->nextPtr;
            delete temp;
            return;
        }

        Node<B> *current = head;
        while (current->nextPtr != nullptr && current->nextPtr->data != data) {
            current = current->nextPtr;
        }

        if (current->nextPtr == nullptr) {
            return; // Data not found
        }

        Node<B> *temp = current->nextPtr;
        current->nextPtr = current->nextPtr->nextPtr;
        delete temp;
    }

    // Traversal and printing of the list
    void traverse()
    {
        Node<B> *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->nextPtr;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;
    list.addItem(1);
    list.addItem(2);
    list.addItem(3);
    list.addItem(4);
    list.addItem(5);
    list.addItem(6);
    list.addItem(7);
    list.addItem(8);
    list.traverse();
    list.deleteItem(2);
    list.traverse();

    return 0;
}
