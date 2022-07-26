#pragma once

#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class CSolution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode node(0, head), * prev = &node;
        while (prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;

            prev->next = second;
            prev = first;
        }
        return node.next;
    }
};
