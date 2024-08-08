#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data=d;
        next=prev=NULL;
    }
};
class Linkedlist
{
public:
    Node *head;
    Node *tail;
    Linkedlist()
    {
        tail=head=NULL;
    }

    void AddNode(int data)
    {
        Node* newNode=new Node(data);
        if(head==NULL)
            tail=head=newNode;
        else
        {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    Node* createNode(int d)
    {
        Node *ptr;
        ptr=new Node(d);
        if(ptr!=NULL)
        {
            ptr->data=d;
            ptr->next=ptr->prev=NULL;
        }
        return ptr;
    }

    void display()
    {
        Node* current=head;
        while(current != NULL)
        {
            cout<<current->data<<"   ";
            current=current->next;
        }

    }

    Node* Search(int enterD)
    {
        // current pointer to head
        Node* current=head;
        while(current != NULL)
        {
            //check data of current node == dataentered
            if(current->data != enterD)
            {
                //make current->next in current so we can point next node in linkedlist
                current=current->next;

            }
            else
            {
                return current;
            }
        }
        cout<<"the data not found"<<endl;
        return NULL;
    }

    void Delete(int dataDeleted)
    {
        //return node i searched for
        Node * pDeleted =Search(dataDeleted);
        if(pDeleted==NULL) //out //ignore the next steps
            return ;


        if(pDeleted==head)//delete the first node
        {
            if(pDeleted==tail)//delete the first node and it is the only node // tail=head=firstNode
            {
                tail=head=NULL;
            }
            else  //delete the first node and there are other nodes
            {
                head=head->next; //we now move to next node
                head->prev=NULL; // make the prev of next node = null as first element
            }

        }
        else if(pDeleted==tail)//delete the last node
        {
            tail=tail->prev; // make the taul point to prev node
            tail->next=NULL; //next of prev node will be null
        }
        else // we delete with nodelist
        {
            pDeleted->prev->next=pDeleted->next;
            pDeleted->next->prev=pDeleted->prev;
        }

        delete pDeleted;
    }

// Insert Node to list
    int Insert(int d, int loc)
    {
        int Count=0;
        Node *pPtr, *pTemp;  // create pointer type node
        pPtr=createNode(d); // Assin to function createNode
        if(pPtr!=NULL)
        {
            Count = 1 ;
            if(head==NULL)  // List May be Contain One Node or Not Nodes
            {
                head=tail=pPtr; // one node
            }
            else
            {
                if(loc == 0)  // location = 0 - insert in first
                {
                    pPtr->next=head;
                    head ->prev=pPtr;
                    head =pPtr;
                }
                else
                {
                    pTemp= head ; //location !=0 loop to location
                    for(int i=0; i<loc-1 && pTemp!=NULL; i++)
                    {
                        pTemp=pTemp ->next;
                    }
                    if(pTemp==tail|| pTemp==NULL)  //tail of list
                    {
                        // add node at the end
                        tail->next=pPtr; // tail => next = ptr
                        pPtr->prev=tail; // ptr =>  prev = tail
                        tail=pPtr;

                    }
                    else   // middle or at the specific
                    {
                        pTemp->next->prev=pPtr;
                        pPtr->next=pTemp->next;
                        pPtr->prev=pTemp;
                        pTemp->next=pPtr;
                    }
                }
            }
        }
    }
};

//push
int push(int data)
{
    int indicate=0;
    Node *pPtr;
    pPtr = this->createNode(data);
    if(pPtr!=nullptr)
    {
        if(Linkedlist->tail == Null) //no list
            Linkedlist.tail =pPtr;
        else{
            pPtr->prev = Linkedlist.tail;
            Linkedlist->tail=pPtr;
        }
    }
}
int main()
{
    int enterD, deleteD1,deleteD2;
    Linkedlist linkedlist;
    for(int i = 2; i<8 ; i++)
    {
        linkedlist.AddNode(i);
    }

    linkedlist.display();
    cout<<endl;
    cout<<"please enter data you search for in linkedlist"<<endl;
    cin>>enterD;
    Node* searchD = linkedlist.Search(enterD);
    if(searchD->data==enterD)
        cout<< "the data your search for is " << searchD->data<<endl;

    cout<<"delete 2 nodes"<<endl;
    cin>>deleteD1>>deleteD2;
    linkedlist.Delete(deleteD1);
    linkedlist.Delete(deleteD2);
    cout<<"linkedlist after delete"<<endl;
    linkedlist.display();
    cout<<endl<<"\n \n-----------New Node-------"<<endl;
     cout<<endl<<"enter data and position:"<<endl;
    int dataI, position;
    cout<<endl<<"enter data: ";
    cin>>dataI;
    cout<<"enter position: ";
    cin>>position;
    linkedlist.Insert(dataI,position);
    cout<<endl<<"linkedlist after insert"<<endl;
    linkedlist.display();
    cout<<endl;


    return 0;
}
