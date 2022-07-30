#include<stack>
#include<vector>

using namespace std;

/*
    note: 单调栈 + 哨兵
    1. 单调栈性质：栈内元素保持单调递增/减，如果新元素比栈顶元素大则入栈，否则一直出栈直到栈顶比新元素小
    2. 对于一个高度，需要确定左右边界，则可以对高度求面积、使用单调栈，可以在出栈的时候得到边界求面积
    3. 为了免去对栈判空和遍历结束后栈不为空的特殊判断，高度vector前后加上0的高度，作为哨兵

*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if (size == 1) return heights[0];

        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        size = heights.size();

        stack<int> S;
        int max = 0;

        for (int i = 0; i < size; i++) {
            while (!S.empty() && heights[S.top()] > heights[i]) {
                int h = heights[S.top()];
                S.pop();
                int w = i - S.top() - 1;
                int cur = h * w;
                if (cur > max) max = cur;
            }
            S.push(i);
        }
        return max;
    }
};