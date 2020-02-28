//26.二叉搜索树与双向链表
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution
{
private:
    void convertHelper(TreeNode *cur, TreeNode *&pre)
    {
        if (cur == nullptr)
        {
            return;
        }
        convertHelper(cur->left, pre);
        cur->left = pre;
        if (pre)
        {
            pre->right = cur;
        }
        pre = cur;

        convertHelper(cur->right, pre);
    }

public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == nullptr)
        {
            return nullptr;
        }
        TreeNode *pre = nullptr;
        convertHelper(pRootOfTree, pre);

        TreeNode *result = pRootOfTree; //head
        while (result->left)
        {
            result = result->left;
        }
        return result;
    }
};