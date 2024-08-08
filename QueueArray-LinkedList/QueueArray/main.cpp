#include <iostream>
using namespace std;
int arr[5];
int top = 0;
int Enqueue(int data)
{
    int retVal =0;
    if(top<5)
    {
        arr[top]=data;
        top++;
        retVal=1;
    }
    return retVal;
}
int Dequeue()
{
    int retVal =-1;
    if(top>-1)
    {
        retVal=arr[0];
        for(int i=0; i<top-1; i++)
        {
            arr[i]=arr[i+1];
        }
        top--;
    }
}

// linkedList
struct Node
{
    int Data;
    Node *pNext;
};
Node *pHead = NULL;
Node *pTail = NULL;

Node* createNode(int d)
{
    Node *ptr;
    ptr=new Node;
    if(ptr!=NULL)
    {
        ptr->Data=d;
        ptr->pNext=NULL;
    }
    return ptr;
}
int Enqueue1(int data)
{
    int retVal =0;
    Node *pPtr = createNode(data);
    if(pPtr!=NULL)
    {
        if(pHead==NULL)
        {
            pHead=pTail=pPtr;
        }
        else{
            pTail->pNext=pPtr;
            pTail=pPtr;
        }
        retVal=1;
    }
    return retVal;
}
int Dequque2()
{
    int retVal = 0;
    Node *pPtr;
    pPtr = pHead;
    if(pHead !=NULL)
    {
        if(pHead==pTail)
        {
            pHead=pTail=NULL;
        }
        else
        {
            pHead=pHead->pNext;
            delete pPtr;
        }
        retVal = -1;
    }
    return retVal;
}
int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    cout<<"=====Array after Enqueue====="<<endl;
    for(int i=0; i<5; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl<<endl<<"======Array After Dequeue===="<<endl;
    Dequeue();
    Dequeue();
    Dequeue();
    for(int i=0; i<2; i++)
    {
        cout<< arr[i] <<" ";
    }

cout<<endl<<endl<<"Queue in Linkedlist"<<endl;
cout<<Enqueue1(10)<<endl;
    cout<<Enqueue1(20)<<endl;
    cout<<Enqueue1(30)<<endl;
    cout<<Enqueue1(40)<<endl;

    cout<<"delete item done " <<Dequque2();


    return 0;
}
