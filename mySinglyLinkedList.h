#ifndef MYLIST_MYSINGLYLINKEDLIST_H
#define MYLIST_MYSINGLYLINKEDLIST_H

#include <list>

template<typename Elem>
class mySinglyLinkedList {
public:
    mySinglyLinkedList();

    int size();
    bool isEmpty();

    void InsertFirst(const Elem &e);
    void DeleteFirst();

    void InsertLast(const Elem &e);
    void DeleteLast();

protected:
    struct Node {
        Elem &element;
        Node *next;

        Node(const Elem &e = nullptr, Node *n = nullptr)
                : element(e), next(n) {};

    };

private:
    Node *head, *tail;
    int count;

};

template<typename Elem>
mySinglyLinkedList<Elem>::mySinglyLinkedList()
        : head(nullptr), tail(nullptr), count(0) {};

template<typename Elem>
int mySinglyLinkedList<Elem>::size() {
    return count;
}

template<typename Elem>
bool mySinglyLinkedList<Elem>::isEmpty() {
    return size() == 0;
}

template<typename Elem>
void mySinglyLinkedList<Elem>::InsertFirst(const Elem &e) {
    Node *newFirst = new Node(e);
    head = newFirst;
    count++;

}

template<typename Elem>
void mySinglyLinkedList<Elem>::DeleteFirst() {
    Node *temp = head;
    head = head->next;
    delete temp;
    count--;

}

template<typename Elem>
void mySinglyLinkedList<Elem>::InsertLast(const Elem &e) {
    Node *newLast = new Node(e);
    tail->next = newLast;
    tail = newLast;
    count++;

}

template<typename Elem>
void mySinglyLinkedList<Elem>::DeleteLast() {
    Node *temp = head;
    while (temp->next == tail) {
        temp = temp->next;
    }
    tail = temp;
    tail->next = nullptr;
    delete temp->next;
    delete temp;
    count--;
}
#endif //MYLIST_MYSINGLYLINKEDLIST_H
