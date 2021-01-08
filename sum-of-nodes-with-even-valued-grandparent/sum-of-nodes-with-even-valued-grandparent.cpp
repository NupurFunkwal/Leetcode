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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int temp=0;
        if((root->val)%2==0){
            if(root->left!=NULL){
                TreeNode* lc=root->left;
                if(lc->left!=NULL){
                    temp+=(lc->left)->val;
                }
                if(lc->right!=NULL){
                    temp+=(lc->right)->val;
                }
            }
            if(root->right!=NULL){
                TreeNode* rc=root->right;
                if(rc->left){
                    temp+=rc->left->val;
                }
                if(rc->right){
                    temp+=rc->right->val;
                }     
            }            
        }
        else{
            ;
        }
        return temp+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
        
    }
};
