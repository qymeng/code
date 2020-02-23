//6.旋转数组的最小数字
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        int size = rotateArray.size();
        //(1)给出数组为空
        if (size == 0)
        {
            return 0;
        }
        //(2)循环查找
        int left = 0, right = size - 1;
        int mid = 0;
        while (rotateArray[left] >= rotateArray[right])
        {
            //<1>分界点
            if (right - left == 1)
            {
                mid = right;
                break;
            }
            mid = (left + right) / 2;
            //<2>[left],[right],[mid]三者相等
            if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid])
            {
                return minNumber(rotateArray, left, right);
            }
            //<3>中间元素位于前面的非递减
            //此时最小元素位于中间元素的后面
            if (rotateArray[mid] >= rotateArray[left])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return rotateArray[mid];
    }

private:
    int minNumber(vector<int> &num, int left, int right)
    {
        int result = num[left];
        for (int i = left + 1; i < right; i++)
        {
            if (num[i] < result)
            {
                result = num[i];
            }
        }
        return result;
    }
};

// int main()
// {
//     Solution s;
//     //vector<int> num = {0, 1, 2, 3, 4, 5};
//     //vector<int> num = {4, 5, 6, 7, 1, 2, 4};
//     vector<int> num = {2, 2, 2, 2, 2, 1, 2};
//     int result = s.minNumberInRotateArray(num);
//     cout << result;

//     return 0;
// }