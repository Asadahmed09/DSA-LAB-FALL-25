/*1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
 Input: A singly linked list of integers.
 Output: true if the list reads the same forward and backward, false otherwise.
 Hint: Use a fast/slow pointer to find the middle, then reverse the second half and
compare.*/
#include<iostream>
using namespace std;

class Node
{
public:
    Node* next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* FindMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* Reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev; 
}

bool IsPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL)
        return true;

    Node* mid = FindMiddle(head);
    Node* secondHalf = Reverse(mid);  

    Node* p1 = head;
    Node* p2 = secondHalf;

    while(p2 != NULL)
    {
        if(p1->data != p2->data)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

int main()
{
    Node* l1 = new Node(5);
    Node* l2 = new Node(6);
    l1->next = l2;
    Node* l3 = new Node(7);
    l2->next = l3;
    Node* l4 = new Node(6);
    l3->next = l4;
    Node* l5 = new Node(5);
    l4->next = l5;

    cout << (IsPalindrome(l1) ? "true" : "false");
}
