//23.二叉搜索树的后序遍历序列
class Solution
{
private:
    bool judge(vector<int> &sequence, int left, int right)
    {
        if (left >= right)
        {
            return true;
        }
        int i = right;
        while (i > left && sequence[i - 1] > sequence[right])
        {
            i--;
        }
        for (int j = i - 1; j >= left; j--)
        {
            if (sequence[j] > sequence[right])
            {
                return false;
            }
        }
        return judge(sequence, left, i - 1) && judge(sequence, i, right - 1);
    }

public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int size = sequence.size();
        if (size == 0)
        {
            return false;
        }
        return judge(sequence, 0, size - 1);
    }
};