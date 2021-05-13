#include<bits/stdc++.h>
using namespace std;


// Given a singly linked list with head node head, return a middle node of linked list.
// If there are two middle nodes, return the second middle node.


class Node 
{
public:
    int data;
    Node* next;
};


/* Function to get the middle of the linked list */
Node* middleNode(Node* head) 
{
    if(head == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int main()
{
    /* 
        Create a linked list
        3->6->9->15->30 
    */

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
  
    // allocate 5 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
  
  
    head->data = 3; 
    head->next = second; 
    
    second->data = 6; 
    second->next = third;
  
    third->data = 9; 
    third->next = fourth;

    fourth->data = 15; 
    fourth->next = fifth;
  
    fifth->data = 30; 
    fifth->next = NULL;
    
    cout << "The middle node of given linked list is " << middleNode(head)->data;

    return 0;

}