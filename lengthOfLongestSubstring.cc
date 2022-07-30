#include <unordered_set>
#include <string>

using namespace std;
/*
    note: 滑动窗口
    每次检查窗口右边的字符串，如果进入窗口后，字符串有重复，
    则将窗口左边的字符串移出窗口，直到满足题目要求
    time: O(n)
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) return 0;
        
        unordered_set<char> chr_set;
        int max_len = 0;
        int left = 0;
        for (int i = 0; i < len; i++) {
            while (chr_set.find(s[i]) != chr_set.end()) {
                chr_set.erase(s[left]);
                left++;
            }
            int cur_len = i - left + 1;
            if (cur_len > max_len) max_len = cur_len;
            chr_set.insert(s[i]);
        }
        return max_len;
    }
};