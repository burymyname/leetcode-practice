#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        int i = row;
        int j = 0;
        while (i >= 0 && j <= col) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                j++;
            } else {
                i--;
            }
        }
        return false;
    }
};