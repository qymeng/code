//9.变态跳台阶
//f(1)=1
//f(2)=f(2-1)+f(2-2)            //f(2-2)表示最后一次跳2级
//f(3)=f(3-1)+f(3-2)+f(3-3)
//...
//f(n)=f(n-1)+f(n-2)+f(n-3)+...+f(n-(n-1))+f(n-n)
//    =f(n-1)+f(n-1)
//    =2*f(n-1)
/**
 * 综上:
 * f(n)=1,          n=0
 *     =1,          n=1
 *     =2*f(n-1),   n>=2
 */
class Solution
{
public:
    int jumpFloorII(int number)
    {
        if (number <= 0)
        {
            return 0;
        }
        else if (number == 1)
        {
            return 1;
        }
        else
        {
            //也是用循环不用递归
            int result = 2;
            for (int i = 2; i < number; i++)
            {
                result *= 2;
            }
            return result;
        }
    }
};