#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *npx;
};

typedef struct Node Node;

Node * XOR(Node *a, Node *b)
{
    return((Node *)((uintptr_t)a ^ (uintptr_t)b));
}

Node * findEndNode(Node *head)
{
    Node *prev = NULL,*next = head,*cur ;
    
    while(next != NULL)
    {
        cur = next;
        next = XOR(prev, cur->npx);
        prev = cur; 
    }
    return cur;
}

void insert(Node *head, int data)
{
    Node *end        = findEndNode(head);
    Node *newNode    = new Node();
    newNode->data    = data;
    Node *secondLast = XOR(end->npx,NULL);  
    newNode->npx     = XOR(end,NULL);
    end->npx         = XOR(secondLast, newNode);
}

void print(Node *head)
{
    Node *prev = NULL,*next = head,*cur ;
    
    while(next != NULL)
    {
        cur = next;
        cout<<cur->data<<"->";
        next = XOR(prev, cur->npx);
        prev = cur; 
    }
}

Node * createNewList(int data)
{
    Node *head = new Node();
    head->data = data;
    head->npx  = XOR(NULL,NULL);
    
    return head;
}

int main()
{
    Node *head = createNewList(40);
    
    insert(head,30);
    insert(head,20);
    insert(head,10);
    insert(head,0);
    insert(head,-10);
    
    print(head);
    
    return 1;   
}