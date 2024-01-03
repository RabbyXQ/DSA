#include <iostream>
using namespace std;

template <typename T>
class Node {
    T data;
    Node *next;
public:
    Node() {
        this->data = 0;
        this->next = nullptr;
    }
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    // Getter and Setter functions for data and next pointer
    T getData() {
        return data;
    }

    void setData(T newData) {
        data = newData;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* newNode) {
        next = newNode;
    }
};

template <typename U>
class LinkedList {
    Node<U> *head;
public:
    LinkedList() {
        head = nullptr;
    }

    void add(U data) {
        Node<U>* newNode = new Node<U>(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<U>* temp = head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }

    // Recursive function to add multiple elements using variadic templates
    template<typename... Args>
    void addAll(Args... args) {
        addMultiple(args...);
    }

    void printList() {
        Node<U>* temp = head;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    void reverseList() {
        Node<U>* prev = nullptr;
        Node<U>* current = head;
        Node<U>* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->getNext();
            current->setNext(prev);
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    void reversekElementList(int k) {
        head = reverseKNodes(head, k);
    }

private:
    Node<U>* reverseKNodes(Node<U>* head, int k) {
        Node<U>* prev = nullptr;
        Node<U>* current = head;
        Node<U>* nextNode = nullptr;
        int count = 0;

        while (current != nullptr && count < k) {
            nextNode = current->getNext();
            current->setNext(prev);
            prev = current;
            current = nextNode;
            count++;
        }

        if (nextNode != nullptr) {
            head->setNext(reverseKNodes(nextNode, k));
        }

        return prev;
    }

    // Recursively add multiple elements
    template<typename First, typename... Rest>
    void addMultiple(First first, Rest... rest) {
        add(first);
        addMultiple(rest...);
    }

    // Base case for the recursive addMultiple function
    void addMultiple() {}
};

int main() {
    LinkedList<int> *llist = new LinkedList<int>();

    // Adding multiple elements using addAll function
    llist->addAll(1, 2, 3, 4, 5);

    cout << "List after adding multiple elements: ";
    llist->printList();

    cout << "Original List: ";
    llist->printList();

    cout << "Reversed List: ";
    llist->reverseList();
    llist->printList();

    int k = 2;
    cout << "Reversed K-element List (k = " << k << "): ";
    llist->reversekElementList(k);
    llist->printList();

    delete llist;
    return 0;
}
