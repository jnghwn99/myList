#ifndef MYLIST_MYDOUBLYLINKEDLIST_H
#define MYLIST_MYDOUBLYLINKEDLIST_H

template<typename Elem>
class myDoublyLinkedList {
public:
    myDoublyLinkedList();

    int size();
    bool isEmpty();

    void insertFirst(const Elem &e);
    void insertLast(const Elem &e);

    void deleteFirst();
    void deleteLast();

protected:
    struct Node {
        Elem &element;
        Node *next, *prev;

        Node(const Elem &e = nullptr, Node *n = nullptr, Node *p = nullptr);

    };

private:
    Node *header, *trailer;
    int count;

};

template<typename Elem>
myDoublyLinkedList<Elem>::myDoublyLinkedList()
        : header(nullptr), trailer(nullptr), count(0) {};

template<typename Elem>
int myDoublyLinkedList<Elem>::size() {
    return count;
}

template<typename Elem>
bool myDoublyLinkedList<Elem>::isEmpty() {
    return size() == 0;
}

template<typename Elem>
void myDoublyLinkedList<Elem>::insertFirst(const Elem &e) {
    Node *newFirst = new Node(e);
    Node *oldFirst = header->next;

    header->next = newFirst;
    newFirst->prev = header;
    oldFirst->prev = newFirst;
    count++;

}

template<typename Elem>
void myDoublyLinkedList<Elem>::insertLast(const Elem &e) {
    Node *newLast = new Node(e);
    Node *oldLast = trailer->prev;

    oldLast->next = newLast;
    newLast->next = trailer;
    trailer->prev;
}

template<typename Elem>
void myDoublyLinkedList<Elem>::deleteFirst() {
    Node *oldFirst = header->next;
    Node *newFirst = header->next->next;

    header->next = newFirst;
    newFirst->prev = header;
    delete oldFirst;
    count--;

}

template<typename Elem>
void myDoublyLinkedList<Elem>::deleteLast() {
    Node *oldLast = trailer->prev;
    Node *newLast = trailer->prev->prev;

    newLast->next = trailer;
    trailer->prev = newLast;
    delete oldLast;
    count--;
}

#endif //MYLIST_MYDOUBLYLINKEDLIST_H
