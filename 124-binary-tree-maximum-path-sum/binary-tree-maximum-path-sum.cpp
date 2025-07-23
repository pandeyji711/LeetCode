/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
long long ans = LLONG_MIN; 
long long solve(TreeNode* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return root->val;
    long long l = LLONG_MIN;
    long long r = LLONG_MIN;

    if (root->left != nullptr)
        l = max(l, solve(root->left));
    if (root->right != nullptr)
        r = max(r, solve(root->right));

    long long maxx = max({0LL, l, r});
      ans=max({ans,l,r});
    long long tem = 1LL * root->val + maxx;
    long long tem2 = LLONG_MIN;
    if (l != LLONG_MIN && r != LLONG_MIN)
        tem2 = 1LL * l + r + root->val;
    ans = max({ans, tem, tem2});
    return root->val + maxx;
}
    int maxPathSum(TreeNode* root) {
         ans=max(ans,solve(root)); 
          return ans;
    }
};