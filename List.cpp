#include "List.h"


std::ostream& operator<<(std::ostream& os, List& m) {
    for (Node* cur = m.head; cur != 0; cur = cur->next) {
        os << cur->data;
        os << '@';
    } 
    return os;
}

std::istream& operator>>(std::istream& is, List& m) {
    std::string line;
    m.head = new Node(0, {});
    Node* cur = m.head;
    while (getline(is, line, '@')) {
        std::stringstream ss(line);
        ss >> cur->data;
        cur->next = new Node(cur, {});
        cur->next->prev = cur;
        cur = cur->next;
    } 
    cur = cur->prev;
    delete cur->next;
    m.tail = cur;
    return is;
}

Node::Node(Node* prev, Circle data) : prev{prev}, next{0}, data{data} { 
    if (prev) {
        if (prev->next) next = prev->next;
    }
}

Node::~Node() {
    /*
    if (prev != 0) {
        prev->next = next;
    }
    if (next != 0) {
        next->prev = prev;
    }
    */
}


List::List() : head{0}, tail{0} {}

void List::add(Circle c) {
    if (tail) {
        tail->next = new Node(tail, c);
        tail->next->prev = tail;
        tail = tail->next;
    }
    else {
        tail = new Node(head, c);
        if (head == 0) {
            head = tail;
            head->next = 0;
            head->prev = 0;
        }
    }
}

void List::add(int idx, Circle c) {
    Node* cur = head;
    for (; idx > 0 && cur != 0; idx--, cur = cur->next) ;
    Node* n = new Node(cur, c);
    if (cur != 0) {
        n->next = cur->next;
        if (cur->next) cur->next->prev = n;
        n->prev = cur;
        cur->next = n;
    }
    else {
        cur = n;
        cur->prev = tail;
        cur->next = 0;
        if (tail) tail->next = cur;
        tail = cur;
    }
    if (head == 0) head = cur;
}

void List::makeHead(Circle c) {
    Node* n = new Node(0, c); 
    if (head) head->prev = n;
    n->next = head;
    head = n;
}

bool List::deleteIf(Circle c) {
    for (Node* cur = head; cur != 0; cur = cur->next) {
        if (cur->data == c) {
            if (cur == head) {
                head = head->next;
            }
            if (cur == tail) {
                tail = tail->prev;
            }
            if (cur->prev) cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            delete cur;
            return true;
        }
    }
    return false;
}

int List::deleteAllIf(Circle c) {
    int n = 0;  
    for (Node* cur = head; cur != 0; cur = cur->next) {
        if (cur->data == c) {
            if (cur == head) {
                head = head->next;
            }
            if (cur == tail) {
                tail = tail->prev;
            }
            if (cur->prev) cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            delete cur;
            n += 1;
        }
    }
    return n;
}

void List::clear() {
    while (head != 0) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }
    head = tail = 0;
}

List::~List() {
    clear();
}



