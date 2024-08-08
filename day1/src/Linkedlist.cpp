#include "Linkedlist.h"

Linkedlist::Linkedlist()
{
    tail=head=NULL;
}
void Linkedlist::AddNode(int data)
{
    Node* newNode=new Node(data);
    if(head==NULL)
        tail=head=newNode;
    else
    {
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}
void Linkedlist::display()
{
    Node* current=head;
    while(current != NULL)
    {
        cout<<current->data<<"   ";
        current=current->next;
    }

}
Node* Linkedlist::Search(int enterD)
{
    // current pointer to head
    Node* current=head;
    while(current != NULL)
    {
        //check data of current node == dataentered
        if(current->data == enterD)
        {
            return current;
        }
        else
        {
            //make current->next in current so we can point next node in linkedlist
            current=current->next;
        }
    }
    cout<<"the data not found"<<endl;
    return NULL;
}
