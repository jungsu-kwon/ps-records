// https://leetcode.com/problems/design-linked-list

#include <iostream>
using namespace std;
class MyListNode
{
public:
    MyListNode* prev;
    MyListNode* next;
    int val;
    MyListNode(int node_val=0,MyListNode* prev_node=nullptr, MyListNode* next_node=nullptr)
    {
        prev = prev_node;
        next = next_node;
        val  = node_val;
    }
};
class MyLinkedList {
public:
    MyListNode* pre_head;
    MyListNode* post_tail;
    int list_size = 0;
    /** Initialize your data structure here. */
    MyLinkedList() {
        pre_head  = new MyListNode(0,nullptr,nullptr);
        post_tail = new MyListNode(0,pre_head,nullptr);
        post_tail->next = pre_head;
        list_size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= list_size) return -1;
        auto cur_node = pre_head->next;
        for (int i = 0; i < index; ++i)
        {
            cur_node = cur_node->next;
        }
        return cur_node->val;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (list_size == 0)
        {
            MyListNode* node_to_add = new MyListNode(val,pre_head,post_tail);
            pre_head->next = node_to_add;
            post_tail->prev = node_to_add;
        }
        else
        {
            MyListNode* head = pre_head->next;
            MyListNode* node_to_add = new MyListNode(val,pre_head,head);

            pre_head->next = node_to_add;
            head->prev = node_to_add;
        }
        
        list_size++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (list_size == 0)
            return addAtHead(val);
        else
        {
            MyListNode* tail = post_tail->prev;
            MyListNode* node_to_add = new MyListNode(val,tail,post_tail);

            tail->next = node_to_add;
            post_tail->prev = node_to_add;
        }
        list_size++;


    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (list_size < index)
            return;
        else if (list_size == index)
            return addAtTail(val);
        MyListNode* prev_node = pre_head;
        MyListNode* next_node = nullptr;

        for (int i = 0; i < index; ++i)
            prev_node = prev_node->next;
        next_node = prev_node->next;
        
        MyListNode* node_to_add = new MyListNode(val,prev_node,next_node);
        prev_node->next = node_to_add;
        next_node->prev = node_to_add;

        list_size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (list_size <= index)
            return;
        
        MyListNode* prev_node = pre_head;
        MyListNode* node_to_pop = nullptr;
        MyListNode* next_node = nullptr;

        for (int i = 0; i < index; ++i)
            prev_node = prev_node->next;
        
        node_to_pop = prev_node->next;
        next_node = node_to_pop->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
        // delete(node_to_pop);

        list_size--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */