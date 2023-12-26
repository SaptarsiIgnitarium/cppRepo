#include <iostream>
#include <forward_list>
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

//passing tail by reference as we want to modify the original linked list 
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

//passing list as value works here because printing
void print(Node* tail)
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

//passing as value works here as we dont need to modify the original list
bool isCircularList(Node* pos)
{
    //empty list
    if(pos == NULL)
    {
        return true;
    }

    Node* temp = pos -> next;
    while(temp != NULL && temp != pos)
    {
        temp = temp -> next;
    }

    if(temp == pos)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    Node* mylist = NULL;

    insertNode(mylist, 5, 3);
    print(mylist);

    insertNode(mylist, 3, 5);
    print(mylist);

    if(isCircularList(mylist))
    {
        cout << "Linked List is circular" << endl;
    }
    else
    {
        cout << "Linked List is not circular" << endl;
    }

    return 0;
}