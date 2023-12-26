#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* middleNode(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;  //list is empty of has 1 node
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       //moves one step at a time
        fast = fast->next->next; //moves two steps at a time
    }

    return slow;
}

int main()
{
    Node* head = new Node(1); //creating the head node
    Node* second = new Node(2);
    Node* third = new Node(10);
    Node* fourth = new Node(4);

    //connecting the nodes to form the linked list
    head->next = second;
    second->next = third;
    third->next = fourth;

    Node* middle = middleNode(head);

    cout << "The middle node value is: " << middle->data << endl;

    return 0;
}