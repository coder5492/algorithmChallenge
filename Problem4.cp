#include <bits/stdc++.h>
using namespace std;

struct Node
{
  struct Node *left,*right;
  int val;
};

typedef struct Node Node;

Node* newNode(int val)
{
    Node *temp = new Node();
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void print(Node *root)
{
    if(root != NULL)
    {
        cout<<root->val<<" ";
        print(root->left);
        print(root->right);    
    }
    else
        return;
    
}
string serialize(Node *root)
{
    string str;
    if(root == NULL)
        return "N";
    else
    {
        str += to_string(root->val);
        str += serialize(root->left);
        str += serialize(root->right);
    }
    
    return str;
}

void deserialize(string str, Node **root, int* point)
{
    if(str[*point] == 'N')
    {
        (*point)++;
        return ;
    }
    else if(*point > str.length())
    {
        return ;
    }
    else
    {
        (*root) = newNode(((int)str[*point]) - 48);
        (*point)++;
        deserialize( str, &((*root)->left)  , point);
        deserialize( str, &((*root)->right) , point);
    }
}

int main() {
	// your code goes here
	Node *root;
// 	root->left         = newNode(2);
// 	root->right        = newNode(3);
// 	root->left->left   = newNode(4);
// 	root->left->right  = newNode(5);
//     root->right->left  = newNode(6);
// 	root->right->right = newNode(7);
	string c = "124NN5NN36NN7NN";
	int p = 0;
    deserialize(c, &root, &p);
    cout<<serialize(root);
	return 0;
}
    