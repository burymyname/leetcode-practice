#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }

        int i;
        int size = nums.size();
        int left = 0;
        int right = sum;
        for (i = 0; i < size; i++) {
            right -= nums[i];
            if (left == right) return i;
            left += nums[i];
        }

        return -1;
    }
};

class Solution1 {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }

        int total = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (2 * total + nums[i] == sum)
                return i;
            total += nums[i];
        }

        return -1;
    }
};