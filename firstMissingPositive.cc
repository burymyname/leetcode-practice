#include<vector>

using namespace std;

/*
    note: 原地hash
    1. 需要在O(n)时间内，且使用常数级别的额外空间
    2. 对于一个长度为n的数组，其中没有出现的最小正整数只能在[1, n+1]中，因为如果[1, n]都出现了
    那么答案就是n+1，否则就是在[1, n]中没有出现的那个数
    3. f(num[i]) = num[i] - 1 来对数组进行原地映射，最后进行遍历，如果某个nums[i]不满足i+1，则就是缺失的数

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > size || nums[i] == nums[nums[i] - 1]) break;

                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return size + 1;
    }
};