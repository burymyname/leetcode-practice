# leetcode-practice

## leetcode 刷题题解

题目按照出现频率排序

| 题目 | 源码 | 考察点 |
| ---- | ---- | ---- |
| [两数之和](https://leetcode.cn/problems/add-two-numbers/) | [addTwoNumbers.cc](./addTwoNumbers.cc) | 链表操作 |
| [无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) | [lengthOfLongestSubstring.cc](./lengthOfLongestSubstring.cc) | 滑动窗口 |
| [寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays/) | | |
| [最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/) | [longestPalindrome.cc](./longestPalindrome.cc) | 动态规划/中心扩散法 |
| [柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/) | [largestRectangleArea.cc](./largestRectangleArea.cc) | 单调栈 |
| [LRU 缓存](https://leetcode.cn/problems/lru-cache/) | [LRUCache.cc](./LRUCache.cc) | 哈希表+双向链表 |
| [缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/) | [firstMissingPositive.cc](./firstMissingPositive.cc) | 原地哈希 |
| [K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) | [reverseKGroup.cc](./reverseKGroup.cc) | 反转链表 |
| [螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/) | [spiralOrder.cc](./spiralOrder.cc) | 边界界定/按层输出 |
| [出现频率最高的 k 个数字](https://leetcode.cn/problems/g5c51o/) | [topKFrequent.cc](./topKFrequent.cc) | 哈希+堆排序 |
| [跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/) | [jumpII.cc](./jumpII.cc) | 贪心算法 |
| [每日温度](https://leetcode.cn/problems/daily-temperatures/) | [dailyTemperatures.cc](./dailyTemperatures.cc) | 单调栈 |

## 牛客网面试必刷TOP101

### 01 链表
| 题目 | 源码 | 难度 | 思路 | 考察点 |
| ---- | ---- | ---- | ---- | ---- |
| [BM1 反转链表](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=295&tqId=23286&ru=%2Fpractice%2Fd8b6b4358f774294a89de2a6ac4d9337&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295) | [ReverseList.cc](./ReverseList.cc) | 简单 | 链表基础，利用三指针反转链表，<br>可以用一个 fake head 解决头指针特殊处理问题 | |
| [BM2 链表内指定区间反转](https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295) | [reverseBetween.cc](./reverseBetween.cc) | 中等 | 新建一个 fake head，然后指针移动到指定区间，然后进行反转，<br>最后返回 fake_head->next | |
| [BM3 链表中的节点每k个一组翻转](https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295) | [reverseKGroup.cc](./reverseKGroup.cc) | 中等 | 反转的部分封装为函数，传入头尾，返回新头尾。<br>同样需要新建一个 fake head，然后按照 k 个划分需要反转的list头尾，<br>如果还没到 k 就发现 tail 为 NULL，则直接返回。<br>调用函数进行反转后，重新将反转后的 list 重新链接到 prev 和 next | |
