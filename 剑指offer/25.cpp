//25.复杂链表的复制
/**
 * 1.遍历链表，复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面
 * 2.重新遍历链表，复制老节点的随机指针给新结点，如A1.random=A.random.next
 * 3.拆分链表，将链表分为原链表和复制后的链表
 */
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (pHead == NULL)
        {
            return NULL;
        }
        //1.遍历链表，复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面
        RandomListNode *p = pHead;
        while (p != NULL)
        {
            RandomListNode *node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        //2.重新遍历链表，复制老结点的随机指针给新结点，如A1.random=A.random.next
        p = pHead;
        while (p != NULL)
        {
            if (p->random != NULL)
            {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        //3.拆分链表，将链表分为原链表和复制后的链表
        //看成一条链表，连隔一个的结点
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *temp;
        p = pHead;
        while (p->next != NULL)
        {
            temp = p->next;
            p->next = temp->next;
            p = temp;
        }
        return pCloneHead;
    }
};