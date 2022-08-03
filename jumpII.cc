#include<vector>

using namespace std;

/*
    note: 贪心算法
    1. 使用贪心算法需要先确认，局部最优等同于全局最优，否则无法使用贪心
    2. 从当前位置出发，选择能够跳的最远的位置
    3. max是当前能够跳的最远的位置，end是当前边界，到达边界时，更新step
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int max = 0;
        int step = 0;
        int end = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (i <= max) {
                if (max < nums[i] + i) {
                    max = nums[i] + i;
                }
                if (i == end) {
                    end = max;
                    ++step;
                }
            }
        }

        return step;
    }
};