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

void print(Node* head)
{
    //for single node
    Node* temp = head;

    do
    {
        cout << temp -> data << " ";
        temp = temp -> next;

    }while (temp != NULL);

    cout << endl;
}

Node* reversedLinkedList(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;

    return head;
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

    cout << "Initial linked list is : ";
    print(head);

    Node* reversed_head = reversedLinkedList(head);
    
    cout << "Reversed linked list is : ";
    print(reversed_head);

    return 0;
}