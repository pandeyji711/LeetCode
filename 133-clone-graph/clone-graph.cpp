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
    void dfs(Node* node,unordered_map<Node*,int>&vism,unordered_map<Node*,Node*>&m)
    {
          if(node==nullptr)return ;
                vism[node]++;
                  vector<Node*>copy;
                Node* tem=new Node(node->val,copy);
                m[node]=tem;
                vector<Node*>v;
                v=node->neighbors;
                for(int i=0;i<v.size();i++)
                {
                      if(vism.find(v[i])==vism.end()){
                       dfs(v[i],vism,m);
                      
                      }
                       m[node]->neighbors.push_back(m[v[i]]);
                }
    }


    Node* cloneGraph(Node* node) {
          unordered_map<Node*,Node*>m;
          unordered_map<Node*,int>vism;
        dfs(node,vism,m);
   return  m[node];
    }
};
// node 1
// n 2,4
// node 2
// n 1 3