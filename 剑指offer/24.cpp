//24.二叉树中和为某一值的路径
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
    vector<vector<int>> buffer;
    vector<int> temp;

public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        if (root == NULL)
        {
            return buffer;
        }
        temp.push_back(root->val); //*
        if (expectNumber - root->val == 0 && root->left == NULL && root->right == NULL)
        {
            buffer.push_back(temp);
        }
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);
        temp.pop_back(); //*
        return buffer;
    }
};