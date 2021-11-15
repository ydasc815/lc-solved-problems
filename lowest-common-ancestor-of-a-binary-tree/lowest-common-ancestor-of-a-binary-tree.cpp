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
    vector<TreeNode*> tr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> tr1, tr2;
        vector<TreeNode*> temp;
        searchNode(root, p, temp);
        tr1 = tr;
        tr.clear(), temp.clear();
        searchNode(root, q, temp);
        tr2 = tr;
        int i=0;
        while(i<tr1.size() && i<tr2.size() && tr1[i] == tr2[i]) i++;
        return tr1[--i];
        
    }
    
    void searchNode(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if(root == nullptr) return;
        path.push_back(root);
        if(root == target) {
            tr = path;
            return;
        }
        else {
            searchNode(root->left, target, path);
            searchNode(root->right, target, path);
            path.pop_back();
        }
    }
};