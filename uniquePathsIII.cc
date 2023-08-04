/*
    NOTES:
        该题其实以前做过，但是忘干净了...
        隐约记得是dfs，但是结束条件怎么判断不记得了，最后还是看题解做出来的。
        题目要求，每个无障碍方格都需要走一遍，但是不能重复。
        说明结束条件为：当前方格为终点，且总块数为所有无障碍方格块数。
        
        首先需要先计算所有无障碍方格块数。然后从开始块进行dfs遍历。
        然后从当前块开始，方向为上下左右遍历，这个枚举就行了。
        当最后遍历到终点时，就会返回1作为函数返回值，将四个方向的结果相加返回给上一层，
        层层迭代，最后返回到最上层就是路径总数了。
        
        在遍历的过程中，为了避免重复访问，将遍历过的方块置为-1，结束后再改回0即可。
*/

#include <vector>

using namespace std;

class Solution {
public:
    int direct[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        int sx = 0, sy = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) count++;
                else if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }

        return dfs(grid, sx, sy, count+1);
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int left) {
        if (x < 0 || x >= grid.size() || 
            y < 0 || y >= grid[x].size() || 
            grid[x][y] < 0) {
            return 0;
        }

        if (grid[x][y] == 2) {
            return left == 0;
        }

        grid[x][y] = -1;
        int path = 0;
        for (int i = 0; i < 4; i++) {
            path += dfs(grid, x+direct[i][0], y+direct[i][1], left-1);
        }
        grid[x][y] = 0;
        return path;
    }
};