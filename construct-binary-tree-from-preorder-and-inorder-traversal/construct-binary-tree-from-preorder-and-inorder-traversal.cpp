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
    TreeNode* helper(vector<int> &preorder, size_t pre_start, size_t pre_end, vector<int>& inorder, size_t in_start, size_t in_end, unordered_map<int,size_t> & inorder_idx){
        
        if(pre_end<=pre_start || in_end<=in_start){
            return NULL;
        }
        
        size_t root_idx_inorder = inorder_idx[preorder[pre_start]];        
        size_t left_sub_size = root_idx_inorder - in_start;
        
        TreeNode* root= new TreeNode(preorder[pre_start]);
        root->left = helper(preorder, pre_start+1 , pre_start+1+left_sub_size, inorder, in_start, root_idx_inorder, inorder_idx);
        root->right = helper(preorder, pre_start+1+left_sub_size, pre_end, inorder, root_idx_inorder+1, in_end, inorder_idx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //hashing
        //size_t : unsigned integer type data
        unordered_map<int,size_t> inorder_idx;
        for(size_t i=0;i<inorder.size();i++){
            inorder_idx.emplace(inorder[i],i);
        }
        
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inorder_idx);
    }
};