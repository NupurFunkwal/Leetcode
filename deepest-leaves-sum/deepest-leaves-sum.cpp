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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        int level=0;
        int sum=0;
        while(q.empty()==false){
            TreeNode* temp= q.front();
            q.pop();
            
            if(temp!=NULL){
                sum+=temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            else if(temp==NULL){
                if(q.empty()==true){
                    return sum;
                }
                else{
                    level++;
                    sum=0;
                    q.push(NULL);
                }      
            }
            
        }
        
        return sum;
        
    }
        
};
