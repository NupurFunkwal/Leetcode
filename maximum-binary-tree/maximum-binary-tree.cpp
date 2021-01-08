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
    TreeNode *construct(vector<int>& nums, int beg, int last){
        if(beg==last){
            TreeNode *root= new TreeNode(nums[beg]);        
            return root;
            
        }
        else if(beg>last){
            return NULL;
        }
        
        int max_index=beg;
        for(int i=beg+1;i<=last;i++){
            if(nums[i]>nums[max_index]){
                max_index=i;
            }
        }
        TreeNode *root= new TreeNode(nums[max_index]);
        root->left= construct(nums, beg, max_index-1);
        root->right= construct(nums, max_index+1, last);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n= nums.size();
        if(n==0){
            return NULL;
        }
        return construct(nums, 0, n-1);
        
    }
};
