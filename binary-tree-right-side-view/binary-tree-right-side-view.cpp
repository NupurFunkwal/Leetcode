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
    void add(TreeNode* root, vector<int> &ans, int h){
        if(root == NULL){
            return;
        }
        
        if(ans.size() == h){
            ans.emplace_back(root->val);
        }
        
        add(root->right, ans, h+1);
        add(root->left, ans, h+1);
        
    }
        
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        add(root, ans, 0);
        return ans;
    }
};