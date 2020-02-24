//13.调整数组顺序使奇数位于偶数前面
class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        vector<int> result;
        int num = array.size();
        for (int i = 0; i < num; i++)
        {
            if (array[i] % 2 == 1) //奇数
            {
                result.push_back(array[i]);
            }
        }
        for (int i = 0; i < num; i++)
        {
            if (array[i] % 2 == 0) //偶数
            {
                result.push_back(array[i]);
            }
        }
        array = result;
    }
};