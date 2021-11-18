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
    set<int> s;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        vector<int> temp = traversal;
        sort(temp.begin(), temp.end());
        return temp == traversal && s.size() == temp.size();
    }
    
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        inorder(root->left);
        traversal.push_back(root->val);
        s.insert(root->val);
        inorder(root->right);
    }
};