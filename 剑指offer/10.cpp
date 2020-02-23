//10.矩形覆盖
//还是斐波那契数列
class Solution
{
public:
    int rectCover(int number)
    {
        if (number <= 0)
        {
            return 0;
        }
        else if (number == 1)
        {
            return 1;
        }
        else if (number == 2)
        {
            return 2;
        }
        else
        {
            int a = 1, b = 2, result = 3;
            for (int i = 3; i < number; i++)
            {
                a = b;
                b = result;
                result = a + b;
            }
            return result;
        }
    }
};