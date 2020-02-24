//16.合并两个排序的链表
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        //(1)排除特殊情况
        if (pHead1 == NULL)
        {
            return pHead2;
        }
        else if (pHead2 == NULL)
        {
            return pHead1;
        }
        //(2)
        ListNode *head = NULL;
        ListNode *p = NULL;
        if (pHead1->val <= pHead2->val)
        {
            p = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            p = pHead2;
            pHead2 = pHead2->next;
        }
        head = p;
        while (pHead1 != NULL && pHead2 != NULL)
        {
            if (pHead1->val <= pHead2->val)
            {
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        if (pHead1 == NULL)
        {
            p->next = pHead2;
        }
        else
        {
            p->next = pHead1;
        }
        return head;
    }
};