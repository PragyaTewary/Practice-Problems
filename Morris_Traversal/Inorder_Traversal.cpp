#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Given a binary tree. Find the inorder traversal of the tree without using recursion and without using extra space.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

// Function to find rightmost node of left node
Node *getRightMostNode(Node *curr, Node *leftNode)
{
    while (leftNode->right != NULL && leftNode->right != curr)
    {
        leftNode = leftNode->right;
    }
    return leftNode;
}

// Function to find inorder traversal using Morris Traversal
vector<int> inOrder(Node *root)
{
    Node *curr = root;
    vector<int> ans;
    while (curr != NULL)
    {
        Node *leftNode = curr->left;
        if (leftNode == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *rightMostNode = getRightMostNode(curr, leftNode);
            if (rightMostNode->right == NULL)
            {
                rightMostNode->right = curr;
                curr = curr->left;
            }
            else
            {
                rightMostNode->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    string s, ch;
    getline(cin, s);

    Node *root = buildTree(s);

    vector<int> ans;

    ans = inOrder(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;

    return 0;
}