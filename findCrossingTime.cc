/*
    n个箱子 k个工人 1个桥
    优先队列，排序
    1.右边先过，左边再过
    2.效率低的先过
    3.桥上有人，其他先等

    1.为什么循环结束条件不能是while(n)？
    虽然箱子被搬空，但是此时可能还有多个工人还在搬运箱子过程中，或者在等待过桥，
    所以条件应该为 while (remain > 0 || !picks.empty() || !rightpq.empty())
    
    2.为什么puts和picks压栈的数据是realtime+搬运/放下时间？
    因为在过桥时，只存在一个人过桥的可能，这个过桥时间段内出现的新的工人都只能等待，
    所以直接将压栈的字段为结束搬运/放下的时间，只要时间小于此时过桥工人的过桥时间，
    就将其弹出优先队列，知道不满足为止。

    3.如何保证realtime是最后一个工人到达左边的时间？
    由于结束循环的条件最后一个为!rightpq.empty()，即只要右边排队过桥队列已经没有人，
    那么循环就结束了，不会进行到计算puts的步骤。这也是将计算puts和picks放在前面的原因。
*/

#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    using PNT = pair<int, int>; // pair of number and time

    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto cmp = [&time](int i, int j) {
            return ((time[i][0] + time[i][2]) < (time[j][0] + time[j][2])) || (((time[i][0] + time[i][2]) == (time[j][0] + time[j][2])) && i < j);
        };
        priority_queue<int, vector<int>, decltype(cmp)> leftpq(cmp);
        priority_queue<int, vector<int>, decltype(cmp)> rightpq(cmp);
        priority_queue<PNT, vector<PNT>, greater<PNT>> picks;
        priority_queue<PNT, vector<PNT>, greater<PNT>> puts;

        /* all workers are in left side */
        for (int i = 0; i < k; i++) {
            leftpq.push(i);
        }

        int realtime = 0;
        int worker = 0;
        int remain = n;

        while (remain > 0 || !picks.empty() || !rightpq.empty()) {

            while (!puts.empty() && puts.top().first <= realtime) {
                leftpq.push(puts.top().second);
                puts.pop();
            }

            while (!picks.empty() && picks.top().first <= realtime) {
                rightpq.push(picks.top().second);
                picks.pop();
            }

            int bridge = 0;
            if (!rightpq.empty()) {
                worker = rightpq.top();
                rightpq.pop();
                bridge = time[worker][2];
                realtime += bridge;
                puts.push({realtime + time[worker][3], worker});
            } else if (remain > 0 && !leftpq.empty()) {
            // 只有当还有箱子没搬运时，工人才有过桥的必要
                worker = leftpq.top();
                leftpq.pop();
                bridge = time[worker][0];
                realtime += bridge;
                picks.push({realtime + time[worker][1], worker});
                remain--;
            } else {
            // 此时无人过桥，时间直接跳转到下一个最近的有人要过桥的时间
                int next_time = INT_MAX;
                if (!puts.empty()) {
                    next_time = min(next_time, puts.top().first);
                }
                if (!picks.empty()) {
                    next_time = min(next_time, picks.top().first);
                }
                if (next_time != INT_MAX) {
                    realtime = max(next_time, realtime);
                }
            }
        }
        return realtime;
    }
};
