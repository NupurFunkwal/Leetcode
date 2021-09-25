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
    int find(int ele, vector<int> &array){
        for(int i=0; i<array.size(); i++){
            if(array[i] == ele){
                return i;
            }
        }
        
        return -1;
    }
    
    TreeNode *form(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie){
        if(ps>pe){
            return NULL;
        }
        
        TreeNode *curr = new TreeNode(preorder[ps]);
        
        if(ps == pe){
            return curr;
        }
        
        int index = find(preorder[ps], inorder);
        
        int len = index - is;
        
        curr->left = form(preorder, ps+1, ps+len, inorder, is, index-1);
        curr->right = form(preorder, ps+len+1, pe, inorder, index+1, ie);
        return curr;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        
        return form(preorder, 0, n-1, inorder, 0, n-1);
        
    }
};