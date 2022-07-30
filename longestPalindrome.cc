#include <string>

using namespace std;

class Solution {
public:

    /*
        note: 中心扩散法
        以当前遍历到的字符为中心，分别用两个指针left和right指向左右两边的字符
        首先判断是否和当前字符相等，left和right分别左右推进
        然后判断左右字符是否相等
    */
    string longestPalindrome1(string s) {
        int len = s.length();
        if (len == 0 || len == 1) return s;

        int max_len = 0;
        int max_left = 0, max_right = 0;
        for (int i = 0; i < len; i++) {
            int left = i - 1, right = i + 1, cur_len = 0;
            while (left >= 0 && s[i] == s[left]) {
                cur_len++;
                left--;
            }

            while (right < len && s[i] == s[right]) {
                cur_len++;
                right++;
            }

            while (left >= 0 && right < len && s[left] == s[right]) {
                left--;
                right++;
                cur_len += 2;
            }

            if (cur_len > max_len) {
                max_len = cur_len;
                max_left = left;
                max_right = right; 
            }
        }
        return s.substr(max_left+1, max_len+1);
    }



};