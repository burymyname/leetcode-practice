#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();

        vector<int> left(size, 1);
        for (int i = 0; i < size; ++i) {
            if (i > 0 && ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }

        int right = 0;
        int sum = 0;
        for (int i = size-1; i >= 0; --i) {
            if (i < size-1 && ratings[i] > ratings[i+1]) {
                ++right;
            } else {
                right = 1;
            }

            sum += max(left[i], right);
        }

        return sum;
    }
};