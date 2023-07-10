/*
    NOTES:
    我一开始以为会有trick，想了一会没想到，结果看题解也没有。
    主要思路是将O(n^3)的复杂度降低到O(n^2)，
    首先对数组排序，然后固定一个num[i]，用两个指针j,k分别指向i+1和n-1，
    1.当num[i]+num[j]+num[k]>target时：说明j到k范围内的数值
    任意挑选两个都将大于target，需要将j++
    2.当num[i]+num[j]+num[k]<target时：说明j到k范围内的数值
    任意挑选两个都将小于target，需要k--
    3.当num[i]+num[j]+num[k]=target时：直接返回，不会有更接近的数值了。

*/

#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        if (size == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        long long value = INT_MAX;
        for (int i = 0; i < size - 2; i++) {
            int left = i + 1;
            int right = size - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return sum;
                }

                long long cur = abs(sum - target);
                if (cur < abs(value - target)) {
                    value = sum;
                }
            }
        }

        return value;
    }

};