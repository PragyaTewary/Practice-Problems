#include<bits/stdc++.h>
using namespace std;


// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit.
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807
 


class Node 
{
public:
    int data;
    Node* next;
};


Node* addTwoNumbers(Node* l1, Node* l2) 
{
    Node* curr = new Node();
    curr->data = 0;
    Node* head = curr;
    int carry = 0;
    while(l1 != NULL || l2 != NULL)
    {
        int s1 = (l1 != NULL)? l1->data : 0;
        int s2 = (l2 != NULL)? l2->data : 0;
        int sum = s1 + s2 + carry;
        carry = sum/10;
        curr->next = new Node();
        curr->next->data = sum%10;
        curr = curr->next;
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)
            l2 = l2->next;
    }
    if(carry > 0)
        curr->next = new Node();
        curr->next->data = carry;
    
    return head->next;
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
    /* 
        Create two linked lists 
      
        1st 3->6->9->5
        2nd 1->5->3
      
    */
  
    Node* newNode;
  
    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 1;
  
    Node* head2 = new Node();
    head2->data = 3;
  
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
  
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 5;
    head1->next = newNode;
    head2->next->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 3;
    head1->next->next = newNode;


    Node* head3;
     
    head3 = addTwoNumbers(head1, head2);
    printList(head3);
    return 0;
}