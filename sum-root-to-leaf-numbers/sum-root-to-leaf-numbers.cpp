/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int parent_val){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return (parent_val*10)+root->val;
        }
        
        int current_val= (parent_val*10)+root->val;
        int left= helper(root->left, current_val);
        int right= helper(root->right, current_val);
        
        return left+right;
    }
    
    int sumNumbers(TreeNode* root) {
        return helper(root,0);        
    }
};
