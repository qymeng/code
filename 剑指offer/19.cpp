//19.顺时针打印矩阵
class Solution
{
public:
    vector<int> printMatrix(vector<vector<int>> matrix)
    {
        //(1)排除非法情况
        vector<int> result;
        int row = matrix.size();
        if (row == 0)
        {
            return result;
        }
        int col = matrix[0].size();
        if (col == 0)
        {
            return result;
        }
        //(2)转圈
        int left = 0, right = col - 1, top = 0, bottom = row - 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                result.push_back(matrix[top][i]);
            }
            if (top < bottom)
            {
                for (int i = top + 1; i <= bottom; i++)
                {
                    result.push_back(matrix[i][right]);
                }
            }
            if (top < bottom && left < right)
            {
                for (int i = right - 1; i >= left; i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
            }
            if (top + 1 < bottom && left < right)
            {
                for (int i = bottom - 1; i >= top + 1; i--)
                {
                    result.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return result;
    }
};
