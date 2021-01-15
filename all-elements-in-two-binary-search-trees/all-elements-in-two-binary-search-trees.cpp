 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getlist(TreeNode *root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        getlist(root->left, ans);
        ans.push_back(root->val);
        getlist(root->right, ans);
        
    }
    
    vector<int> merge(vector<int> one, vector<int> two, vector<int> &ans){
        int n1= one.size();
        int n2= two.size();
        
        int a=0,b=0;
        while(a<n1 && b<n2){
            if(one[a]<two[b]){
                ans.push_back(one[a++]);
            }
            else{
                ans.push_back(two[b++]);
            }
        }
        
        if(a<n1){
            while(a<n1){
                ans.push_back(one[a++]);
            }
        }
        if(b<n2){
            while(b<n2){
                ans.push_back(two[b++]);
            }
        }
        
        return ans;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> one; 
        getlist(root1, one);
        vector<int> two;
        getlist(root2, two);
        
        vector<int> ans;
        merge(one, two, ans);
        return ans;
        
    }
};
