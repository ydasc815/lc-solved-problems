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
    vector<int> traversal;
    map<int, int> m;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        vector<int> temp = traversal;
        sort(temp.begin(), temp.end());
        int dupflag = 1;
        for(auto& i:m) if(i.second > 1) { dupflag = 0; break; }
        return temp == traversal && dupflag;
    }
    
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root->left);
        traversal.push_back(root->val);
        m[root->val]++;
        inorder(root->right);
    }
};