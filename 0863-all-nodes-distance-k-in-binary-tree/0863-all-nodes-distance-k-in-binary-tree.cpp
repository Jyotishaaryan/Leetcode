/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
        unordered_map<TreeNode* , TreeNode*> par;
        set<TreeNode*>s;
        vector<int> ans;

        void findParent(TreeNode* root)
        {
            if(root == NULL)
            {
                return;
            }
            if(root->left)
            {
                par[root->left] = root;
            }
            if(root->right)
            {
                par[root->right] = root;
            }
            findParent(root->left);
            findParent(root->right);
        }
        void solve(TreeNode * node, int k)
        {
            if(s.find(node) != s.end())
            {
                return;
            }
            s.insert(node);
            if(k==0)
            {
                ans.push_back(node->val);
            }
            if(node->left)
            {
                solve(node->left , k-1);
            }
            if(node->right)
            {
                solve(node->right , k-1);
            }
            if(par[node])
            {
                solve(par[node], k-1);
            }
            return;
        }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            findParent(root);
            solve(target,k);
            return ans;
        
    }
};
        