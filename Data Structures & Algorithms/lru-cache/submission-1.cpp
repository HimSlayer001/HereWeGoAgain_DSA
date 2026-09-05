#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int key;
    int val;

    ListNode* prev;
    ListNode* next;

    ListNode(int k, int v)
    {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache
{
private:
    int capacity;

    // key -> address of corresponding node
    unordered_map<int, ListNode*> mp;

    // HEAD = Most Recently Used
    // TAIL = Least Recently Used
    ListNode* head;
    ListNode* tail;

    void removeNode(ListNode* node)
    {
        // If node is not the head
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        else
        {
            // node is head
            head = node->next;
        }

        // If node is not the tail
        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
        else
        {
            // node is tail
            tail = node->prev;
        }
    }

    void addHead(ListNode* node)
    {
        // New node becomes first node
        node->prev = nullptr;
        node->next = head;

        // If list already has nodes
        if (head != nullptr)
        {
            head->prev = node;
        }
        else
        {
            // List was empty
            tail = node;
        }

        head = node;
    }

public:

    LRUCache(int capacity)
    {
        this->capacity = capacity;

        head = nullptr;
        tail = nullptr;
    }

    int get(int key)
    {
        auto it = mp.find(key);

        // Key doesn't exist
        if (it == mp.end())
        {
            return -1;
        }

        // it->second is ListNode*
        ListNode* node = it->second;

        // This node was just accessed,
        // so it becomes most recently used.
        removeNode(node);
        addHead(node);

        return node->val;
    }

    void put(int key, int value)
    {
        auto it = mp.find(key);

        // CASE 1: Key already exists
        if (it != mp.end())
        {
            ListNode* node = it->second;

            // Update value
            node->val = value;

            // Make it most recently used
            removeNode(node);
            addHead(node);

            return;
        }

        // CASE 2: Key doesn't exist
        ListNode* newNode = new ListNode(key, value);

        // Add to hashmap
        mp[key] = newNode;

        // Add to front of linked list
        addHead(newNode);

        // Cache exceeded capacity
        if (mp.size() > capacity)
        {
            ListNode* lru = tail;

            // Remove from hashmap
            mp.erase(lru->key);

            // Remove from linked list
            removeNode(lru);

            // Free dynamically allocated memory
            delete lru;
        }
    }

    ~LRUCache()
    {
        // Delete remaining nodes
        ListNode* current = head;

        while (current != nullptr)
        {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }
};