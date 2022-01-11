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
    int findmax(TreeNode *root, int &maxsum){
        if(root==NULL){
            return 0;
        }
        
        int left= findmax(root->left, maxsum);
        int right= findmax(root->right, maxsum);
        
        if(left<0){
            left=0;
        }
        
        if(right<0){
            right=0;
        }
        
        maxsum = max(maxsum, root->val+left+right);
        
        return root->val + max(left,right);
    }
    
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        
        int ans = INT_MIN;
        
        int temp = findmax(root, ans);
        if(temp>ans){
            return temp;
        }
        else return ans;
        
    }
};