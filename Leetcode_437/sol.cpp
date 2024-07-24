// link :"https://leetcode.com/problems/path-sum-iii/solutions/5466692/prefix_sum-in-treesdfs-approach-9792/"
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int target) 
    {
        unordered_map<long long, int> prefix_sum;
        prefix_sum[0] = 1;
        return dfs(root, target, 0, prefix_sum);
    }

private:
    int dfs(TreeNode* node, long long target, long long curr_sum, unordered_map<long long, int>& prefix_sum) 
    {
        if (!node) {
            return 0;
        }

        curr_sum += node->val;
        int path_cnt = prefix_sum[curr_sum - target];

        prefix_sum[curr_sum]++;

        path_cnt += dfs(node->left, target, curr_sum, prefix_sum);
        path_cnt += dfs(node->right, target, curr_sum, prefix_sum);

        prefix_sum[curr_sum]--;

        return path_cnt;
    }
};

int main() {
    // create as per your tree looks....
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution solution;
    int target = 8;
    cout << "Number of paths that sum to " << target << ": " << solution.pathSum(root, target) << endl;

    return 0;
}
