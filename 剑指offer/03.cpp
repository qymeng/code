//3.从尾到头打印链表
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> result;
        ListNode *p = head;

        while (p != NULL)
        {
            result.insert(result.begin(), p->val);
            p = p->next;
        }

        return result;
    }
};