#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
    }
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* current = root;
        for(auto ch : word)
        {
            if(current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }

            current = current->children[ch];
        }
        current->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode* node = findNode(word);

        if(node != NULL && node->isEnd == true)
        {
            return true;
        }
        else{
            return false;
        }
    }

    bool startsWith(string prefix)
    {
        TrieNode* node = findNode(prefix);
        
        if(node != NULL)
        {
            return true;
        }
        else{
            return false;
        } 
    }   

    TrieNode* findNode(string word)
    {
        TrieNode* current = root;
        for(auto ch : word)
        {
            if(current->children.find(ch) == current->children.end())
            {
                return NULL;
            }

            current = current->children[ch];
        }
        return current;
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;  //return true
    cout << trie.search("app") << endl;    //return false
    cout << trie.startsWith("app") << endl;  //return true
    trie.insert("app");
    cout << trie.search("app") << endl;   //return true 

    return 0;
}