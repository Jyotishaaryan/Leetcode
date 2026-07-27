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
    void allPaths(TreeNode* root , string str , vector<string> &ans)
    {
        if(root->left == NULL && root->right == NULL)
        {
        ans.push_back(str);
        return;
        }

        if(root->left)
        {
            allPaths(root->left , str + "->" + to_string(root->left->val), ans);
        }
        if(root->right)
        {
            allPaths(root->right , str + "->" + to_string(root->right->val), ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str = to_string(root->val);

        allPaths(root , str , ans);

        return ans;
    }
};