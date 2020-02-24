//11.二进制中1的个数
class Solution
{
public:
    int NumberOf1(int n)
    {
        unsigned int flag = 1; //数阶
        int count = 0;         //计数

        while (flag)
        {
            if (flag & n)
            {
                count++;
            }
            flag <<= 1; //左移，二进制
        }

        return count;
    }
};