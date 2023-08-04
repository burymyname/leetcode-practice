#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        long long sum = 0;
        int len = INT_MAX;
        int p = 0;

        for (int i = 0; i < size; i++) {
            sum += nums[i];
            while ((p <= i) && ((sum-nums[p]) >= target)) {
                sum -= nums[p];
                p++;
            }
            if (sum >= target) {
                len = min(len, i - p + 1);
            }
        }

        if (len == INT_MAX) len = 0;
        return len;
    }
};