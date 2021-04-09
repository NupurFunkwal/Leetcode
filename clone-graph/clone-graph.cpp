/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node;
        }
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.emplace(node);
        m.emplace(node, new Node(node->val));
        while(q.empty()==false){
            Node* temp = q.front();
            q.pop();
            vector<Node*> :: iterator it;
            for(it = (temp->neighbors).begin(); it!= (temp->neighbors).end(); it++){
                if(m.find(*it) == m.end()){
                    m.emplace(*it, new Node((*it)->val));
                    q.emplace(*it);
                }
                m[temp]->neighbors.emplace_back(m[*it]);
            }
        }
        return m[node];
    }
};