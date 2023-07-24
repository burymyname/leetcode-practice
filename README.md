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

## leetcode 每日一题

工作后每天熟悉一下

| 题目 | 难度 | 源码 | 关键思路 |
| ---- | ---- | ---- | ---- |
| [1465. 切割后面积最大的蛋糕](https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/) | 中等 | [maxAreaOfCake.cc](./maxAreaOfCake.cc) | 由于切法贯穿整个蛋糕，所以最大的宽度和长度一定会相交，只要找出最大长度宽度相乘即是最大面积 |
|[2532. 过桥的时间](https://leetcode.cn/problems/time-to-cross-a-bridge/description/) | 困难 | [findCrossingTime.cc](./findCrossingTime.cc) | 用四个优先队列，分别存储四个状态的工人，然后模拟搬运过程 |
| [16. 最接近的三数之和](https://leetcode.cn/problems/3sum-closest/description/) | 中等 | [threeSumClosest.cc](./threeSumClosest.cc) | 排序+双指针 |
| [1911. 最大子序列交替和](https://leetcode.cn/problems/maximum-alternating-subsequence-sum/description/) | 中等 | [maxAlternatingSum.cc](./maxAlternatingSum.cc) | 动态规划，但是需要区分单数双数情况 |
| [2544. 交替数字和](https://leetcode.cn/problems/alternating-digit-sum/description/) | 简单 | [alternateDigitSum.cc](./alternateDigitSum.cc) | 位数的奇偶性会决定和的正负，只需要观察到这一点，就能简化程序 |
| [931. 下降路径最小和](https://leetcode.cn/problems/minimum-falling-path-sum/description/) | 中等 | [minFallingPathSum.cc](./minFallingPathSum.cc) | 动态规划，当前块的最小和为上一行的左中右三个块的最小和的最小值加上当前块的值，整个矩阵的最小和为最后一行的所有块的最小和的最小值 |
| [979. 在二叉树中分配硬币](https://leetcode.cn/problems/distribute-coins-in-binary-tree/) | 中等 | [distributeCoins.cc](./distributeCoins.cc) | 递归解决问题，将问题抽象简化，只要分析出子数的硬币数-节点数就是需要移动到父节点的硬币数，就可以递归解决 |

## leetcode 剑指Offer 专项突破

### 整数专题

| 题目 | 源码 | 难度 | 思路 | 考察点 |
| ---- | ---- | ---- | ---- | ---- |
| []() | []() | 简单 | | 模拟计算 |

## leetcode 算法面试题汇总

### 0.开始之前

| 题目 | 源码 | 难度 | 思路 | 考察点 |
| ---- | ---- | ---- | ---- | ---- |
| [只出现一次的数字](https://leetcode.cn/problems/single-number/) | [singleNumber.cc](./singleNumber.cc) | 简单 | 用异或，遍历一遍即可 | 异或的性质 |
| [多数元素](https://leetcode.cn/problems/majority-element/) | [majorityElement.cc](./majorityElement.cc) | 简单 | 把众数记为 +1，把其他数记为 -1 | Boyer-Moore 投票算法 |
| [搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/) | [searchMatrixII.cc](./searchMatrixII.cc) | 中等 | 从左下角/右上角开始遍历， 大于则向上/下，小于则向左/右 | 二分 |
| [合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/) | [merge.cc](./merge.cc) | 简单 | 从后开始遍历，最后只需要移动B数组的值 |  倒序归并 |
| [鸡蛋掉落](https://leetcode.cn/problems/super-egg-drop/) | []() | 困难 | 

## 华为题库
| 题目 | 源码 | 难度 | 思路 | 考察点 |
| ---- | ---- | ---- | ---- | ---- |
| [接雨水](https://leetcode.cn/problems/trapping-rain-water/) | [trap.cc](./trap.cc) | 困难 | 首先用单调栈递减存放高度，如果遇到比栈顶更大的高度，则循环出栈，计算面积。<br> 首先出栈栈顶，高度为左右高度中最小的减去当前高度，宽度为左右索引的差。 | 单调栈 |
| [接糖果](https://leetcode.cn/problems/candy/) | [candy.cc](./candy.cc) | 困难 | 贪心算法，首先从左遍历，按照从左到右递增的顺序进行计算，再从右到左计算，取两次的最大值 | 贪心算法 |


常见技巧

- 二分查找：定义左右边界，每次找中间
- 双指针：一快一慢，快的遍历，慢的在特定状态下移动
- 滑动窗口
    - 窗口内是什么
    - 如何移动窗口起始位置
    - 如何移动窗口结束位置
- 虚拟头节点：解决单独处理头节点的问题
- 单调队列
    - [滑动窗口中的最大数](https://leetcode.cn/problems/sliding-window-maximum/)  
    - 队列中维护从大到小的数，但是不必存放所有的数，因为滑动窗口在移动过程中，只要最大数依然在窗口内，最大数左边的数都没有意义。  
    - 所以在遍历过程，只要新进入的数比队列尾部的数大，就把队尾的数出列，再让该数入列即可，保证队列单调递减。  
    - 用双端队列合适
    - 什么时候用单调栈：需要找到一个元素右边或者左边第一个比自己大或小的元素的位置。

- 二叉树统一迭代法
    - 根节点入栈后，紧接其后压入一个 `null`，用这个当做指针判断是否该标记输出。

- 回溯
     - 确定回溯递归函数参数
     - 确定终止条件
     - 确定遍历过程

- 贪心
    - 将问题分解为若干个子问题
    - 找出最合适的贪心策略
    - 求解每个子问题最优解
    - 将局部最优堆叠为全局最优

- 动态规划
    - 确定dp数组下标含义
    - 确定递推公式
    - dp数组如何初始化
    - 确定遍历顺序
    - 举例推导

- 欧拉道路：从无向图的一个节点出发，每条边刚好经过一次(一笔画)  
连通的无向图，最多只有两个奇点，，则一定存在欧拉道路
- 欧拉回路：如果奇点不存在，则从任意点出发，一定会回到该点。

- 字典树/前缀树：以字符串每个字母做节点的树
