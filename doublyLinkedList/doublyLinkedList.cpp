#include <iostream>
using namespace std;

struct Node
{
    struct Node* prev;
    int data;
    struct Node* next;
}*Head,*Last;

struct Node* createDLL(int a[], int n);

void DisplayDLL(struct Node* head);

struct Node* createDLL2(int a[], int n);




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

}

