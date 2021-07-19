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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return NULL;
        }
        
        stack<TreeNode*> s;
        for(int i=0; i<n; i++){
            TreeNode *current = new TreeNode(nums[i]);
            while(!s.empty() && s.top()->val < nums[i]){
                current->left = s.top();
                s.pop();
            }
            
            if (!s.empty()){
                s.top()->right = current;
            }
            
            s.push(current);
        }
        
        TreeNode *head=NULL;
        while(!s.empty()){
            head = s.top();
            s.pop();
        }
        
        return head;
    }
};