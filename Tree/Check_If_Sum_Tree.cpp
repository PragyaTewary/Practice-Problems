#include <bits//stdc++.h>
using namespace std;


// Given a Binary Tree. Return 1 if, for every node X in the tree other than the leaves,
// its value is equal to the sum of its left subtree's value and its right subtree's value. 
// Else return 0.
// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0.
// A leaf node is also considered a Sum Tree.


struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};


int SumOfTree(Node* root)
{
    if(root == NULL)
            return 0;
            
    else if(root->left == NULL && root->right == NULL)
            return root->data;

    else
    {
        if(root->data == SumOfTree(root->left) + SumOfTree(root->right))
        {
            return 2*root->data;
        }
    }
    
}
bool isSumTree(Node* root)
{
    if(root->data == SumOfTree(root)/2)
    {
        return true;
    }
    
    return false;
}



int main()
{
    Node *root=new Node(66);
	root->left=new Node(9);
	root->right=new Node(24);
	root->left->left=new Node(5);
	root->left->right=new Node(4);
	root->right->right=new Node(12);
    root->right->right->left=new Node(3);
	root->right->right->right=new Node(9);

    cout <<isSumTree(root) << endl;

    return 1;
}
