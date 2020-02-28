//28.数组中出现次数超过一半的数字
//目标数超过数组长度的一半，对数组同时去掉两个不同的数字，
//到最后剩下的一个数就是该数字。
//如果剩下两个，那么这两个也是一样的，就是结果
class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int size = numbers.size();
        if (size == 0)
        {
            return 0;
        }

        int result = numbers[0];
        int times = 1;
        for (int i = 1; i < size; i++)
        {
            if (times == 0)
            {
                result = numbers[i];
                times = 1;
            }
            else if (numbers[i] == result)
            {
                times++;
            }
            else
            {
                times--;
            }
        }

        times = 0;
        for (int i = 0; i < size; i++)
        {
            if (numbers[i] == result)
            {
                times++;
            }
        }

        if (times * 2 <= size)
        {
            result = 0;
        }

        return result;
    }
};