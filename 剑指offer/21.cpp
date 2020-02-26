//21.栈的压入、弹出序列
class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        //(1)排除非法情况
        int size = pushV.size();
        if (size == 0)
        {
            return false;
        }
        //(2)建立辅助栈
        stack<int> s;
        for (int i = 0, j = 0; i < size;)
        {
            s.push(pushV[i++]);
            while (j < size && (!s.empty()) && s.top() == popV[j])
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};