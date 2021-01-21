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
    pair<int, bool> isbal(TreeNode *root){
        if(root==NULL){
            return make_pair(0,1);
        }
        if(root->left==NULL && root->right==NULL){
            return make_pair(1,1);
        }
        
        pair<int,bool> h_left= isbal(root->left);
        pair<int,bool> h_right= isbal(root->right);
       
        if(h_left.second==0 || h_right.second==0){
            return make_pair(-1,0);
        }
        else if(abs(h_left.first-h_right.first)>1){
            return make_pair(-1,0);
        }
        else{
            int height= max(h_left.first,h_right.first)+1;
            return make_pair(height,1);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans= isbal(root);
        if(ans.second==1){
            return 1;
        }
        else return false;
        
    }
};
