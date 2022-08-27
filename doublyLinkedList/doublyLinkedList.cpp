#include <iostream>
using namespace std;

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*Head,*Last;


//function declaration


struct Node* createDLL(int a[], int n);

void DisplayDLL(struct Node* head);

struct Node* createDLL2(int a[], int n);

int countNodesDLL(struct Node* head);

struct Node* InsertDLL(struct Node* head, int pos, int val);

struct Node* DeleteDLL(int pos, struct Node* head);

struct Node* ReverseDLL(struct Node* head);





//functions

struct Node* ReverseDLL(struct Node* head)
{
    //empty list or list with single node

    if (!head || !head->next)
        return head;


    //non empty list with more than one node

    struct Node* p = head, * temp = NULL;

    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        if (!p->prev)
            head = p;
        p = p->prev;
        
    }
    return head;
}


struct Node* DeleteDLL(int pos, struct Node* head)
{
    //check valid postion
    if (pos<1 || pos>countNodesDLL(head))
    {
        cout << "Invalid position passed -> Deletion is not possible " << endl;
        return head;
    }

    //deletion on first node
    struct Node* p = head;
    if (pos == 1)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
    }

    //delete any other node
    else
    {
        for (int i = 0;i < pos - 1;i++)
            p = p->next;

        p->prev->next = p->next;

        if (p->next)
            p->next->prev = p->prev;
    }
    delete p;

    return head;
}


struct Node* InsertDLL(struct Node* head, int pos, int val)
{
    //check pos
    if (pos<0 || pos > countNodesDLL(head))
    {
        cout << "Invalis position -> Insertion is Not possible" << endl;
        return head;
    }
   
    //empty list
    struct Node* temp = new Node;
    temp->data = val;

    if (!head)
    {
        temp->next = temp->prev = NULL;
        head = temp;
        return head;
    }
    //non empty but insert before head
    if (pos == 0)
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;   
    }
    //non empty insert other than head or last
    else
    {
        struct Node* p = head;

        for (int i = 0;i < pos - 1;i++)
            p = p->next;

        temp->next = p->next;
        temp->prev = p;
        p->next = temp;
        if (temp->next)
            temp->next->prev = temp;
        
    }
    return head;
}


int countNodesDLL(struct Node* head)
{
    if (!head)
        return 0;

    int count = 0;
    struct Node* temp = head;

    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void DisplayDLL(struct Node* head)
{

    //if list empty
    if (!head)
    {
        cout << "List is empty " << endl;
        return;
    }

    //list with one or more than one element
    struct Node* p = head;

    cout << "Elements in the Doubly linked list " << endl;

    while (p)
    {
        cout << p->data<<" ";
        p = p->next;
    }
    cout << endl;
}


struct Node* createDLL2(int a[], int n)
{
    if (n == 0)
        return NULL;

    struct Node* head = new Node,*p;
    p = head;

    for (int i = 0;i < n;i++)
    {
        if (i == 0)
        {
            p->prev = NULL;
        }
        else
        {
            struct Node* temp = new Node;
            temp->prev = p;
            p->next = temp;
            p = temp;
        }
        p->data = a[i];
        p->next = NULL;

        if (n == 1)
            return p;
    }
    return head;
}


struct Node* createDLL(int a[], int n)
{
    //empty list
    if (n == 0) 
        return NULL;
    

    //one node list
    struct Node* head = new Node;
    head->prev = NULL;
    head->data = a[0];
    head->next = NULL;

    if (n == 1)
        return head;

    //more than one node list 
    struct Node* p = head;

    for (int i = 1;i < n;i++)
    {
        struct Node* temp = new Node;
        temp->data = a[i];

        //making doubly linking
        temp->prev = p;
        p->next = temp;
        
        temp->next = NULL;

        //moving the p to newly created node
        p = temp;

    }

    return head;
}



int main()
{
    int a[5] = { 10,20,30,40,50 };
    Head=createDLL2(a, 5);
    DisplayDLL(Head);

    cout << "Number of nodes in list :" << countNodesDLL(Head) << endl;

    Head = InsertDLL(Head, 0, 5);
    cout << "After Insertion" << endl;
    DisplayDLL(Head);

    Head = DeleteDLL(1, Head);
    cout << "After Deletion" << endl;
    DisplayDLL(Head);

    Head = ReverseDLL(Head);
    cout << "After Reversing Doubly linked list " << endl;
    DisplayDLL(Head);

}

