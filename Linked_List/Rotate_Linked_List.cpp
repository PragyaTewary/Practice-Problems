#include<bits/stdc++.h>
using namespace std;

// Given a singly linked list of size n. The task is to rotate the linked list counter-clockwise by k nodes,
// where k is a given positive integer smaller than or equal to length of the linked list.


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* rotate(Node* head, int k)
    {
        Node *curr = head;
        int n=0;
        while(curr != NULL)
        {
            curr = curr->next;
            n++;
        }
        curr = head;
        Node *prev = head;
         
        int rot = k%n;
        if(rot == 0)
            return head;
        while(rot--)
        {
            prev = curr;
            curr=curr->next;
        }
        Node *last = curr; 
        while(last->next != NULL)
        {
            last = last->next;
        }
        
        prev->next = NULL;
        last->next = head;
        return curr;
    }


void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}



int main()
{
    int t;
    cin>>t;  // Number of testcases
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        cin>> k;
        head = rotate(head, k);

        cout << "The rotated linked list is : " <<endl;
        printList(head);
    }
    return 1;

}