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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* pFirstNode = head, * pSecondNode = head, * pPrevNode = head;
		for (int nI = 1; pFirstNode->next != nullptr; nI++)
		{
			pFirstNode = pFirstNode->next;

			if (nI >= n)
			{
				pPrevNode = pSecondNode;
				pSecondNode = pSecondNode->next;
			}
		}

		pPrevNode->next = pSecondNode->next;
		if (pSecondNode == head)
			head = head->next;
		delete pSecondNode;

		return head;
	}
};
