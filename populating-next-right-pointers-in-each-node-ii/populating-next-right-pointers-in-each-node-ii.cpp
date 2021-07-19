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

    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        
        Node *leftmost = root;
        Node *prev;
        
        Node *current = root;
        while(leftmost){
            prev = NULL;
            leftmost = NULL;
            while(current){
                if(current->left){
                    if(prev!=NULL){
                        prev->next = current->left;
                        prev = current->left;
                    }
                    else{
                        leftmost = current->left;
                        prev = current->left;
                    }
                }
                if(current->right){
                    if(prev!=NULL){
                        prev->next = current->right;
                        prev = prev->next;
                    }
                    else{
                        leftmost = current->right;
                        prev = current->right;
                    }
                }

                current = current->next;
            }
            
            if(leftmost == NULL){
                break;
            }
            else current = leftmost;
        }
        
        return root;
    }
};