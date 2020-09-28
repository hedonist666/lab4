#pragma once
#include "Circle.h"
#include <iostream>
#include <string>
#include <sstream>

struct Node {
    Node* prev;
    Node* next;
    Circle data;

    Node();
    Node(Node*, Circle);
    ~Node();
};

struct List {
    Node* head;
    Node* tail;
    List();
    void add(Circle);
    void add(int, Circle);
    void makeHead(Circle);
    bool deleteIf(Circle);
    int deleteAllIf(Circle);
    void clear();
    ~List();
    friend std::ostream& operator<<(std::ostream&, List&);
    friend std::istream& operator>>(std::istream&, List&);
};
