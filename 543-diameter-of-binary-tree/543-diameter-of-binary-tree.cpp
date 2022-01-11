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
    int maxlen=INT_MIN;
    
    int findmax(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        int left= findmax(root->left);
        int right= findmax(root->right);
        
        maxlen = max(left+right+1, maxlen);
        
        return 1+max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int temp = findmax(root);
        return max(temp, maxlen)-1;
    }
};