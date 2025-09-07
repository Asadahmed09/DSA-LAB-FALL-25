#include "iostream"
using namespace std;

class node 
{
public:
    int data;
    node* next;
    node() {
        next = NULL;
    }
};

node* middleNode(node* head)
{
    node* slowPtr = head;
    node* fastPtr = head;
    while(fastPtr != NULL && fastPtr->next != NULL) 
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

void insertNode(node* head, int data)
{
    node* newNode = new node();
    newNode->data = data;

    while(head->next != NULL)
        {
        head = head->next;
    }
    head->next = newNode;
}

void printNodes(node* head)
{
    while(head)
        {
        cout << "Data : " << head->data << " - Next Address : " << head->next << endl;
        head = head->next;
    }
}

node* reverseList(node* head)
{
    node* prev = NULL;
    node* curr = head;
    node* next = NULL;

    while(curr != NULL)
        {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool checkPalindrome(node* head)
{
    if(!head || !head->next) return true;

  
    node* mid = middleNode(head);

    node* secondHalf = reverseList(mid);

    node* firstHalf = head;
    node* temp = secondHalf;

    while(secondHalf != NULL) {
        if(firstHalf->data != secondHalf->data)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main()
{
    node* head = new node();
    head->data = 1;
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);

    printNodes(head);

    cout << "Middle node: " << middleNode(head)->data << endl;
    cout << "Palindrome: " << (checkPalindrome(head) ? "Yes" : "No") << endl;
}
