//15.反转链表
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
    ListNode *ReverseList(ListNode *pHead)
    {
        //(1)空链表
        if (pHead == NULL)
        {
            return NULL;
        }
        //(2)使用栈将指针逆置
        stack<ListNode *> s; //指针栈
        ListNode *p = pHead;
        while (p != NULL)
        {
            s.push(p);
            p = p->next;
        }

        pHead = s.top();
        s.pop();
        p = pHead;
        while (!s.empty())
        {
            p->next = s.top();
            s.pop();
            p = p->next;
        }
        p->next = NULL;
        //(3)返回
        return pHead;
    }
};