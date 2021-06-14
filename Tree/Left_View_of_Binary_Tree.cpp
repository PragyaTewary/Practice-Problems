#include<bits//stdc++.h>
using namespace std;




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