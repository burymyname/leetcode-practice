#include<vector>

using namespace std;

/*
    NOTE:
        由于切割是完整的，所以最大的长度和最大的宽度一定有交叉。
        所以需要先排序，然后按顺序便利找到最长的长度和宽度，
        宽度长度的计算为：当前切割线编号减去前一个切割线编号
        最后需要特殊处理一下最后一条边
*/

class Solution {
public:

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hsize = horizontalCuts.size();
        int wsize = verticalCuts.size();

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxH = horizontalCuts[0];
        int maxW = verticalCuts[0];

        for (int i = 1; i < hsize; i++) {
            maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        maxH = max(maxH, h - horizontalCuts[hsize-1]);

        for (int i = 1; i < wsize; i++) {
            maxW = max(maxW, verticalCuts[i] - verticalCuts[i-1]);
        }
        maxW = max(maxW, w - verticalCuts[wsize-1]);

        return int64_t(maxH) * int64_t(maxW) % 1000000007;
    }
};