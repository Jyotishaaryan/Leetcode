class Solution {
public:
    TreeNode* helper(TreeNode* root, vector<TreeNode*>& result, unordered_set<int>& st) {
        if(root == NULL) return NULL;

        root->left = helper(root->left, result, st);
        root->right = helper(root->right, result, st);

        if(st.find(root->val) != st.end()) {
            if(root->left) result.push_back(root->left);
            if(root->right) result.push_back(root->right);
            return NULL; // delete this node
        }
        return root; // keep this node
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        root = helper(root, result, st);

        if(root != NULL) {
            result.push_back(root); // root survives
        }
        return result;
    }
};

