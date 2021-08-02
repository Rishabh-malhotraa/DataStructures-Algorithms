
//   Definition for singly-linked list.
/**
	 * prev pointer and next pointer
	 * first keep checking next value with curr and update the next's next val
	 * then we need to update the current value
	 * if prev is null then do head as next
	 * else prev = nextptr->next
	 * Increment every pointer ; prev = crr; curr = next ; next = curr->next 
	 *  */

struct ListNode
{
	int val;
	ListNode *next;
};

ListNode *deleteDuplicates(ListNode *head)
{
	if (head == NULL)
		return NULL;

	ListNode *prev = NULL, *curr = head, *next = head->next;

	while (next)
	{
		if (next->val == curr->val)
		{
			while (next && next->val == curr->val)
				next = next->next;

			if (!prev)
				head = next;
			else
				prev->next = next;
		}
		else
		{
			prev = curr;
		}

		curr = next;
		if (next)
			next = next->next;
	}

	return head;
}
