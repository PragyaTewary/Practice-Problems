#include<bits//stdc++.h>
using namespace std;

/*
Given a Binary Tree, print Left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
The task is to complete the function leftView(), which accepts root of the tree as argument.
Left view of following tree is 1 2 4 8.

         1
       /   \
     2       3
   /  \     /  \
  4    5   6    7
   \
    8   
*/


struct Node
{
    int data; 
    struct Node *left; 
    struct Node *right; 
    Node(int k){
        data=k;
        left=right=NULL;
  }
};

void leftView(Node *root)
{
    queue<Node *> q;
    if(root == NULL)
    {
        return;
    }
    q.push(root);
    while(!q.empty())
    {
        int count = q.size();
        for(int i=0; i<count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if(i == 0)
            {
                cout<<(curr->data)<<" ";
            }
    
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->right=new Node(70);
	root->left->left->right=new Node(80);
	
	leftView(root);


}