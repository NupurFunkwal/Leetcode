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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        
        while(!(s.empty()==true && root==NULL)){
            if(root){
                ans.emplace_back(root->val);
                if(root->right){
                    s.push(root->right);
                }
                root=root->left;
            }
            else{
                root=s.top();
                s.pop();
            }
        }
        return ans;
    }
};
