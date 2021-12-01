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
    vector<int> t;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        int h = height(root);
        for(int i=0; i<h; i++) {
            levelorder(root, i);
            if(i%2 != 0) {
                reverse(t.begin(), t.end());
            }
            ret.push_back(t);
            t.clear();
        }
        return ret;
    }
    
    void levelorder(TreeNode* root, int h) {
        if(root == nullptr) return;
        if(h == 0) t.push_back(root->val);
        else {
            levelorder(root->left, h-1);
            levelorder(root->right, h-1);
        }
    }
    
    int height(TreeNode* root) {
        if(root == nullptr) return 0;
        else return 1 + max(height(root->left), height(root->right));
    }
};