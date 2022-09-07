#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();

        stack<int> st;
        int res = 0;
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int h = height[st.top()]; st.pop();

                if (st.empty())
                    break;

                int w = i - st.top() - 1;
                int min = height[st.top()];
                if (height[i] < min) min = height[i];
                res += w * (min - h);
            }
            st.push(i);
        }

        return res;
    }

};