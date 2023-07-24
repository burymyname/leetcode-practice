/*
    NOTE:
        首先涉及到树，大概率是可以用递归方式去求解的，递归需要抽象简化。
        这里设想一颗以a为根的最小子树，该子数仅有三个节点，除去a为根节点外，只有b和c分别为左子节点和右子节点。
        如果该子树的硬币不等于节点数，说明肯定需要从父节点拿来硬币或者从该子树挪到父节点硬币。
        子树和父节点之间移动的硬币数=该子树的硬币数和节点数的差值。对所有子树计算一遍就能够得到移动步数的和。
        所以递归的公式为：
        coins = coins_left + coins_right + node.val
        nodes = nodes_left + nodes_right + 1
        step = | coins - nodes |

        这里的定义还可以再优化：
        d = coins - nodes，step的和就是|d|
        d = d_left + d_right + node.val - 1

*/

#include <cmath>

/**
 Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int coins = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int d = dfs(root->left) + dfs(root->right) + root->val - 1;
        coins += abs(d);
        return d;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return coins;
    }
};