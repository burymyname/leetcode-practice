/*
    NOTES:
        虽然看到题目第一感觉猜到是动态规划，但是还没没有写出状态转移方程。
        题目计算的是奇偶数交替的差值最大值，那么肯定要考虑奇偶数的。
        首先由于奇偶性不同，当前num[i]如果下标在队列中为奇数，那么应该是-num[i]，
        当前num[i]如果下标在队列中为偶数，那么应该是+num[i]
        我能想到的只有上面的部分，下面是题解
        ---------------------------------
        假设f[i]是前i个数值中，以奇数下标结尾的交叉序列最大值；g[i]是前i个数值中，以偶数下标结尾的交叉序列最大值。
        当考虑第i个元素num[i]时：
        如果选择该元素为奇数下标，那么前一个序列最后一个值必定为偶数下标，f[i] = g[i-1] - num[i]，如果不选择加入，
        那么f[i] = f[i-1]
        如果选择该元素为偶数下标，那么前一个序列最后一个值必定为奇数下标，g[i] = f[i-1] + num[i]，如果不选择加入，
        那么g[i] = g[i-1]
        初始时f[0] = 0, g[0] = 0
        经过状态转移方程可以发现，每个f[i]仅仅依赖于前一个g[i-1]和f[i-1]，所以可以只用两个值存储前值

*/
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long f=0, g=0;

        for (int i = 0; i < n; i++) {
            f = max(g-nums[i], f);
            g = max(f+nums[i], g);
        }

        return max(f, g);
    }

};