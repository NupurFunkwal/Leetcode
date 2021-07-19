/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void populate(Node *root){
        while(root){
            root->left->next = root->right;
            
            if(root->next){
                root->right->next = root->next->left;
            }
            root = root->next;
        }
    }
    
    Node* connect(Node* root) {
        Node *head = root;
        while(root && root->left){
            populate(root);
            root = root->left;
        }
        return head;
    }
    
};