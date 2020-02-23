//2.替换空格
class Solution
{
public:
  void replaceSpace(char *str, int length)
  {
    //从前向后数空格数，从后向前组成新字符串
    int count = 0; //空格个数
    //(1)从前向后遍历字符串，数空格个数
    for (int i = 0; str[i] != '\0'; i++)
    {
      if (str[i] == ' ')
      {
        count++;
      }
    }
    //(2)从后向前构造新字符串
    for (int i = length - 1; i >= 0; i--)
    {
      if (str[i] != ' ')
      {
        str[i + 2 * count] = str[i];
      }
      else
      {
        count--;
        str[i + 2 * count] = '%';
        str[i + 2 * count + 1] = '2';
        str[i + 2 * count + 2] = '0';
      }
    }
  }
};