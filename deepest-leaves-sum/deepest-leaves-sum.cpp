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
    
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int left = 1+height(root->left);
        int right = 1+height(root->right);
        
        return max(left,right);
    }
    
    void cal(TreeNode *root, int &sum, int h){
        if(h<1 || root == NULL){
            return;
        }
        
        if(h == 1){
            sum+= root->val;
        }
        
        cal(root->left, sum, h-1);
        cal(root->right, sum, h-1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        
        if(h==0){
            return 0;
        }
        
        int sum=0;
        cal(root, sum, h);
        return sum;
    }
};