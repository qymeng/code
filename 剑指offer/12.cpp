//12.数值的整数次方
//简单快速幂
class Solution
{
public:
    double Power(double base, int exponent)
    {
        long long p = abs((long long)exponent);
        double result = 1.0;
        while (p)
        {
            if (p & 1)
            {
                result *= base;
            }
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1 / result : result;
    }
};