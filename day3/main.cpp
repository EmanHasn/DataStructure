#include <iostream>
using namespace std;

// Push of array
int arr[5];
int Tos=0;
int Push(int data)
{
    int retVal=0;
    if(Tos<5)
    {
        arr[Tos]=data;
        Tos++;
        retVal=1;
    }
    return retVal;
}
// Pop of array
int Pop()
{
    int retVal=0;
    if(Tos>0)
    {
        Tos--;
        retVal=arr[Tos]; // return value of delete
    }
    return retVal;
}

// Push & POP to LinkedList

struct Node
{
    int data;
    struct Node *pPrev;
};

Node *pTail=NULL;

Node* createNode(int d)
{
    Node *ptr;
    ptr=new Node;
    if(ptr!=NULL)
    {
        ptr->data=d;
        ptr->pPrev=NULL;
    }
    return ptr;
}
// Push to Linked list
int Push2(int data)
{
    int retVal=0;
    Node *ptr;
    ptr=createNode(data); // Assin to function createNode
    if(ptr!=NULL) // ptr carry a node
    {
        if(pTail==NULL)  // No list
        {
            pTail=ptr;
            ptr->pPrev=NULL;
        }
        else   // there is list
        {
            ptr->pPrev=pTail;
            pTail=ptr;
        }
        retVal=ptr->data;
    }
    return retVal;
}
// Pop to Linked list
int Pop2()
{
    int retVal=0;
    Node *pTemp;
    pTemp=pTail;
    if(pTail!=NULL) //tail point to node
    {
        pTail=pTail->pPrev;
        retVal=pTemp->data;
    }
    delete pTemp;
    return retVal;
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    cout<<endl<<"*******PUSH**********"<<endl;
    cout<<"array element after push"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl<<"*******POP**********"<<endl;
    cout<<"POP from Array"<<endl;
    cout<<Pop()<<endl;
    cout<<Pop()<<endl;
    cout<<Pop()<<endl<<endl;


    cout<<"*******PUSH**********"<<endl;
    cout<<"Push linkedlist"<<endl;
    cout<<Push2(60)<<" ";
    cout<<Push2(70)<<" ";
    cout<<Push2(80)<<endl<<endl;
    cout<<"*******POP**********"<<endl;
    cout<<"POP linkedlist"<<endl;
    cout<<Pop2()<<endl;
    cout<<Pop2()<<endl;

    return 0;
}
