#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

ListNode* constructedLinkedList(priority_queue<int, vector<int>, greater<int>>& valueQueue);
ListNode* mergeKLists(vector<ListNode*>& lists);
void printList(ListNode* head);

int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);
    //list3->next->next = new ListNode(5);

    vector<ListNode*> listsVec = {list1, list2, list3};
    ListNode* result = mergeKLists(listsVec);

    printList(result);

    return 0;
}

ListNode* constructedLinkedList(priority_queue<int, vector<int>, greater<int>>& valueQueue)
{
    ListNode head(0);  //dummy node
    ListNode* current = &head;

    while(!valueQueue.empty())
    {
        current->next = new ListNode(valueQueue.top());
        valueQueue.pop();
        current = current->next;
    }  
    return head.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    priority_queue<int, vector<int>, greater<int>> valuesQueue;

    for(auto list : lists)
    {
        while(list)
        {
            valuesQueue.push(list->val);
            list = list->next;
        }
    }

    return constructedLinkedList(valuesQueue); 
}

void printList(ListNode* head)
{
    while(head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "null" << endl;
}