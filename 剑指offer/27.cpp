//27.字符串的的排列
/**
 * 递归法，问题转换为先固定第一个字符，求剩余字符的排列；求剩余字符排列时跟原问题一样。
 *(1)遍历出所有可能出现在第一个位置的字符（即：依次将第一个字符同后面所有字符交换）；
 *(2)固定第一个字符，求后面字符的排列（即：在第1步的遍历过程中，插入递归进行实现）。
 */
class Solution
{
private:
    void swap(char &src, char &des)
    {
        char temp = src;
        src = des;
        des = temp;
    }

    void getPermutation(string str, vector<string> &result, int begin)
    {
        if (begin == str.size() - 1) //递归结束条件，索引指向str最后一个元素时
        {
            if (find(result.begin(), result.end(), str) == result.end())
            {
                result.push_back(str);
            }
        }
        else
        {
            for (int i = begin; i < str.size(); i++)
            {
                swap(str[begin], str[i]);
                getPermutation(str, result, begin + 1);
                swap(str[begin], str[i]);
            }
        }
    }

public:
    vector<string> Permutation(string str)
    {
        vector<string> result;
        if (str.empty())
        {
            return result;
        }
        getPermutation(str, result, 0);
        sort(result.begin(), result.end());
        return result;
    }
};