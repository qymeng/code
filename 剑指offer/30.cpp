//30.连续子数组的最大和
/**
 * 使用动态规划
 * F(i)：以array[i]为末尾元素的子数组的和的最大值
 *       F(i) = max(F(i-1)+array[i], array[i])
 * res：所有子数组的和的最大值
 *      res = max(res, F(i))
 */
class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int result = array[0];
        int max = array[0];
        int size = array.size();

        for (int i = 1; i < size; i++)
        {
            max = (max + array[i] > array[i]) ? (max + array[i]) : array[i];
            result = (max > result) ? max : result;
        }

        return result;
    }
};