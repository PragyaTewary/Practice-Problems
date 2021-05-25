#include<bits//stdc++.h>
using namespace std;

// Given the root of a binary tree,
// return the average value of the nodes on each level in the form of an array.
// Answers within 10^-5 of the actual answer will be accepted.


//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Breadth First Search:

vector<double> averageOfLevels(TreeNode* root) 
{
    queue<TreeNode*> q;
    vector<double> ans;
    q.push(root);
    
    while(!q.empty())
    {
        double sum = 0.00000;
        int count = q.size();
        for(int i=0; i<count; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            sum += (double)curr->val;

            if(curr->left != nullptr)
                q.push(curr->left);
            if(curr->right != nullptr)
                q.push(curr->right);    
            
        }
        double avg = sum/count;
        ans.push_back(avg);
    }
    return ans;
}


int main()
{
    TreeNode *root=new TreeNode(10);
	root->left=new TreeNode(9);
	root->right=new TreeNode(20);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(31);
	root->right->right=new TreeNode(7);
	root->right->right->right=new TreeNode(8);

    vector<double> res = averageOfLevels(root);
    for(int i=0; i< res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;

}