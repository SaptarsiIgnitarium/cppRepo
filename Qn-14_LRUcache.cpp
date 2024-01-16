#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache
{
private:
    class Node
    {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k,int v)
        {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;

    void removeNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToFront(Node* node)
    {
        removeNode(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1,-1);  //dummy head node
        tail = new Node(-1,-1);  //dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            moveToFront(node);
            return node->value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        }
        else
        {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addToFront(newNode);

            if(cache.size() > capacity)
            {
                Node* node = tail->prev;
                removeNode(node);
                cache.erase(node->key);
                delete node;
            }
        }
    }
};

int main()
{
    //LRUCache cache(2);  //create an object with capacity 2
    LRUCache* cache = new LRUCache(2);

    cache->put(1,10);
    cache->put(5,37);

    cout << "Value at key 1 is : " << cache->get(1) << endl;
    cout << "Value at key 5 is : " << cache->get(5) << endl;

    //updating an existing value
    cache->put(1,25);
    cout << "Updated value of 1 is :" << cache->get(1) << endl;

    //adding another pair which exceeds the capacity
    cache->put(3,42);
    //key 5 should be removed
    cout << "Value at key 5 is : " << cache->get(5) << endl;

    return 0;

}