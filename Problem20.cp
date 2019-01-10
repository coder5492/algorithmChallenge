#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node * createList(int data)
{
    Node *head = new Node();
    head->data = data;
    head->next = NULL;
}

void insert(Node *head,int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
}

void makeCircular(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}

int findIntersection(Node *head)
{
    Node *fast = head, *slow = head;
    
    while(1)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    
    cout<<"\n";
    slow = head;
    while(1)
    {
        slow = slow->next;
        fast = fast->next;
        if(slow == fast)
            break;
    }
    
    
    return slow->data;
}
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}
int main() {
    Node *list1 = createList(3);
    Node *list2 = createList(99);
    insert(list2,1);
    insert(list1,7);
    insert(list1,8);
    insert(list1,10);
    
    list2->next->next = list1->next->next;
    
    makeCircular(list1);
    
    cout<<findIntersection(list2);
}