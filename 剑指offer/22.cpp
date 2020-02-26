//22.从上往下打印二叉树
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
public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode *> q;
        TreeNode *p;
        //(1)二叉树为空
        if (root == NULL)
        {
            return result;
        }
        //(2)利用队列BFS
        q.push(root);
        while (!q.empty())
        {
            p = q.front();
            result.push_back(p->val);
            if (p->left)
            {
                q.push(p->left);
            }
            if (p->right)
            {
                q.push(p->right);
            }
            q.pop();
        }
        return result;
    }
};