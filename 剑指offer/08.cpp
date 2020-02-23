//8.跳台阶
//跳n级台阶的跳法数f(n)=f(n-1)+f(n-2)
//即求斐波那契数列的第n项
class Solution
{
public:
    int jumpFloor(int number)
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