//29.最小的K个数
class Solution
{
private:
    void adjustHeap(vector<int> &input, int i, int length)
    {
        int child = i * 2 + 1;
        if (child < length)
        {
            if (child + 1 < length && input[child + 1] > input[child])
            {
                child++;
            }
            if (input[child] > input[i])
            {
                int temp = input[i];
                input[i] = input[child];
                input[child] = temp;
                adjustHeap(input, child, length);
            }
        }
    }

public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        vector<int> result;
        int size = input.size();

        if (size == 0 || k == 0 || k > size)
        {
            return result;
        }

        //(1)初始化最大堆
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            adjustHeap(input, i, k);
        }
        //(2)与堆顶进行比较，进行替换
        int i = k;
        while (i < size)
        {
            if (input[0] > input[i])
            {
                int temp = input[i];
                input[i] = input[0];
                input[0] = temp;
                adjustHeap(input, 0, k);
                i = k;
            }
            else
            {
                i++;
            }
        }
        for (int i = 0; i < k; i++)
        {
            result.push_back(input[i]);
        }
        return result;
    }
};