#pragma once


struct ListNode 
{
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

	int val;
	ListNode *next;
};
 
class CSolution 
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* pListNode = new ListNode(), * pNewListHead = pListNode;

		while (list1 != nullptr || list2 != nullptr)
		{
			if (list1 != nullptr && list2 != nullptr)
			{
				if (list1->val < list2->val)
				{
					pListNode->next = list1;
					list1 = list1->next;
				}
				else if (list2 != nullptr)
				{
					pListNode->next = list2;
					list2 = list2->next;
				}
			}
			else if (nullptr != list2)
			{
				pListNode->next = list2;
				list2 = list2->next;
			}
			else if (nullptr != list1)
			{
				pListNode->next = list1;
				list1 = list1->next;
			}
			pListNode = pListNode->next;
		}
		pListNode = pNewListHead;
		pNewListHead = pNewListHead->next;
		delete pListNode;

		return pNewListHead;
    }
};
