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
    void inorder(TreeNode* root , vector<int> &in)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left , in);
        in.push_back(root->val);
        inorder(root->right , in);

    }

    int lower(vector<int> & in, int q)
    {
        int ans  = -1;
        int  l =0;
        int h = in.size()-1;
        while(l<=h)
        {

            int m = l+ (h-l)/2;
            if(in[m] <= q)
            {
             ans = max(ans, in[m]);
             l = m+1;
            }   
            else h = m-1;
        }
       
        return ans;    
    }
    int upper(vector<int> & in, int q)
    {
        int ans  = INT_MAX;
        int  l =0;
        int h = in.size()-1;
        while(l<=h)
        {

            int m = l+ (h-l)/2;
            if(in[m] >= q)
            {
             ans = min(ans, in[m]);
             h = m-1;
            }   
            else l= m+1;
        }
        if (ans == INT_MAX)
            return -1;
        return ans;    
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int> in;
        vector<vector<int>> ans;
        inorder(root,in);
        int n = in.size();
        for(int i = 0; i < q.size(); i++)
        {
            vector<int> v;
            int lb = lower(in, q[i]);
            int ub = upper(in, q[i]);

            v.push_back(lb);
            v.push_back(ub);

            ans.push_back(v);
        }

        return ans;
    }
};