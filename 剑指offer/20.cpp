//20.包含min函数的栈
class Solution
{
private:
    stack<int> s;
    stack<int> sMin;

public:
    void push(int value)
    {
        s.push(value);
        if (sMin.empty())
        {
            sMin.push(value);
        }
        else if (value < sMin.top())
        {
            sMin.push(value);
        }
    }
    void pop()
    {
        if (sMin.top() == s.top())
        {
            sMin.pop();
        }
        s.pop();
    }
    int top()
    {
        return s.top();
    }
    int min()
    {
        return sMin.top();
    }
};