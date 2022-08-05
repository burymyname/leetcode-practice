#include<vector>
#include<stack>

using namespace std;

/*
    note: 单调栈
    1. 单调栈存的是index，而非直接存储温度，相差天数直接通过index计算
    
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size);

        stack<int> S;
        for (int i = 0; i < size; ++i) {
            while (!S.empty() && temperatures[i] > temperatures[S.top()]) {
                int idx = S.top();
                S.pop();
                res[idx] = i - idx;            
            }
            S.push(i);
        }
        return res;
    }
};