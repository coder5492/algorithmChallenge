#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *left, *right;
};

typedef struct Node Node;

Node *createNewNode(int data)
{
    Node *head  = new Node();
    head->data  = data;
    head->left  = NULL;
    head->right = NULL;
}

bool isSubtreeUnival(Node *head, int data)
{    
    if(head == NULL)
        return true;
    else if(head->data != data)
        return false;
    else
    {
        return(isSubtreeUnival(head->left,data) && isSubtreeUnival(head->right,data));
    }
}

bool isTreeUnival(Node *head)
{
    Node *left = head->left, *right = head->right;
    int data = left->data;
    if(left->data != right->data)
        return false;
    else
        return(isSubtreeUnival(left,data) && isSubtreeUnival(right,data));
}

int countUnival(Node *head)
{
    int sum=0;
    if(head == NULL)
        return 0;
    else if(head->left == NULL && head->right == NULL)
        return 1;
    else
    {
        if(isTreeUnival(head))
            sum++;
        sum += countUnival(head->left) + countUnival(head->right);
    }
    return sum;
}

int main() {
    
    Node *head  = createNewNode(0);
    head->left  = createNewNode(1);
    head->right = createNewNode(0);
    head->right->left  = createNewNode(1);
    head->right->right = createNewNode(0);
    head->right->right = createNewNode(0);
    head->right->left->left  = createNewNode(1);
    head->right->left->right = createNewNode(1);
    
    cout<<countUnival(head);
	return 0;
}