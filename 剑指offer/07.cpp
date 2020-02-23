//7.斐波那契数列
class Solution
{
public:
    int Fibonacci(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else
        {
            //!!!使用循环迭代而非递归
            int a = 0, b = 1, result = 1;
            for (int i = 2; i < n; i++)
            {
                a = b;
                b = result;
                result = a + b;
            }
            return result;
        }
    }
};