//4.重建二叉树
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        int len = vin.size();
        if (len == 0) //树为空
        {
            return NULL;
        }

        //(1)创建根节点
        TreeNode *head = new TreeNode(pre[0]);
        //(2)找到中序遍历根节点所在位置，存放于临时变量中
        int temp = 0;
        for (int i = 0; i < len; i++)
        {
            if (vin[i] == pre[0])
            {
                temp = i;
                break;
            }
        }
        //(3)对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
        //利用上述特点对二叉树进行归并，得到子树的中序、前序序列
        vector<int> leftPre, rightPre, leftVin, rightVin;
        for (int i = 0; i < temp; i++)
        {
            leftVin.push_back(vin[i]);
            leftPre.push_back(pre[i + 1]); //前序第一个为根节点
        }
        for (int i = temp + 1; i < len; i++)
        {
            rightVin.push_back(vin[i]);
            rightPre.push_back(pre[i]);
        }
        //(4)递归对子树再进行区分，直到叶子节点
        head->left = reConstructBinaryTree(leftPre, leftVin);
        head->right = reConstructBinaryTree(rightPre, rightVin);

        return head;
    }
};
