#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int count = 1;
        int major = nums[0];
        for (int i = 1; i < size; ++i) {
            if (count == 0) {
                major = nums[i];
                count++;
            } else if (major == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return major;
    }
};