/*
    NOTES:
        其实这道题算动态规划中比较简单的题，因为状态转移方程比较直接。
        假设当前位置为第i行第j列matrix[i][j]，
        那么上一步只能是matrix[i-1][j-1],matrix[i-1][j],matrix[i-1][j+1]之一。
        那么当前位置最小和dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
        另外，注意对j=0和j=n-1列的特判
*/

#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int Min = INT_MAX;
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
            if (dp[0][i] < Min) {
                Min = dp[0][i];
            }
        }

        for (int i = 1; i < n; i++) {
            // i = 0
            int pre = min(dp[i-1][0], dp[i-1][1]);
            dp[i][0] = pre + matrix[i][0];
            Min = dp[i][0];
            // i = 1 ~ n-2
            for (int j = 1; j < n-1; j++) {
                pre = min(dp[i-1][j-1], dp[i-1][j]);
                pre = min(pre, dp[i-1][j+1]);
                dp[i][j] = pre + matrix[i][j];
                Min = min(Min, dp[i][j]);
            }
            // i = n-1
            pre = min(dp[i-1][n-2], dp[i-1][n-1]);
            dp[i][n-1] = pre + matrix[i][n-1];
            Min = min(Min, dp[i][n-1]);
        }

        return Min;
    }
};