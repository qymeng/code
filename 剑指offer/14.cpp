//14.链表中倒数第k个节点
//设置两个指针，第一个指向第1个元素，第二个指向第k个元素
//从前向后遍历，第二个指针指向表尾时，第一个指针指向倒数第k个元素
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        //(1)表不存在
        if (pListHead == NULL)
        {
            return NULL;
        }
        //(2)k不合法
        if (k <= 0)
        {
            return NULL;
        }
        //(3)设置指针，遍历链表
        ListNode *p = pListHead;
        ListNode *q = pListHead;
        for (int i = 1; i < k; i++)
        {
            q = q->next;
            if (q == NULL) //表长小于k
            {
                return NULL;
            }
        }
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }

        return p;
    }
};