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
    void cal(TreeNode *root, TreeNode *parent, TreeNode *grand, int &sum){
        if(root == NULL){
            return;
        }
        
        if(grand!= NULL && (grand->val)%2 == 0){
            sum+=root->val;
        }
        
        grand = parent;
        parent = root;
        
        cal(root->left, parent, grand, sum);
        cal(root->right, parent, grand, sum);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int sum=0;
        cal(root, NULL, NULL, sum);
        return sum;
    }
};