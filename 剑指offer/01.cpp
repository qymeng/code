// 1.二维数组中的查找
class Solution {
 public:
  bool Find(int target, vector<vector<int>> array) {
    //从左下角向右上角查找
    int rows = array.size();     //行数
    int cols = array[0].size();  //列数
    int i = rows - 1, j = 0;     //左下角元素坐标
    while (i >= 0 && j < cols) {
      if (target < array[i][j])  //查找元素比当前元素小，向上
      {
        i--;
      } else if (target > array[i][j])  //查找元素比当前元素大，向右
      {
        j++;
      } else {
        return true;  //找到
      }
    }
    return false;
  }
};
