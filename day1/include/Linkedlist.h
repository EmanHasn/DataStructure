#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <Node.h>
#include <iostream>
using namespace std;
class Linkedlist
{
public:
    Node *head;
    Node *tail;
    Linkedlist();
    void AddNode(int);
    void display();
    Node* Search(int);
};

#endif // LINKEDLIST_H
