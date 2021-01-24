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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        
        while(!(root==NULL && s.empty()==true)){
            if(root){
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top();
                s.pop();
                ans.emplace_back(root->val);
                root=root->right;
            }
        }
        return ans;
        
    }
};
