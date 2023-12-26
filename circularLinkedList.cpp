#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    //constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }

    //~Node(){}
};

void insertNode(Node* &tail, int element, int d)
{
    //empty list
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
        //tail -> next = tail;
    }
    else
    {
        //assuming the element is present in the list
        Node* curr = tail;

        while(curr -> data != element)
        {
            curr = curr -> next;
        }

        //element found in curr
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}

void print(Node* &tail)
{
    //for single node
    Node* temp = tail;

    do
    {
        cout << tail -> data << " ";
        tail = tail -> next;

    }while (tail != temp);

    cout << endl;
}

int main()
{
    Node* list = NULL;

    insertNode(list, 5, 3);
    print(list);

    insertNode(list, 3, 5);
    print(list);

    return 0;
}