/***
 * Question: Burn Tree from a given target node
 * Link:https://practice.geeksforgeeks.org/problems/burning-tree/1/#
 ***/


class Solution {
  public:
    void findParent(unordered_map<Node*, Node*>& parent, Node* root, Node* par, Node** targetAdd, int target){
        if(root == NULL) return;
        if(root -> data == target) *targetAdd = root;
        parent[root] = par;
        
        findParent(parent, root->left, root, targetAdd, target);
        findParent(parent, root-> right, root, targetAdd, target);
        
    }
    
    // Using BFS Traversal
    int minTimeUsingBfs(Node* root, unordered_map<Node*, Node*>& parent ){
        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(root);
        vis[root]= true;
        int time = 0;
        
        while(!q.empty()){
            bool fl = 0;
            int siz = q.size();
            
            for (int i =0; i < siz; i ++){
                 Node* p = q.front();
                 q.pop();
                 
                if(parent[p] && !vis[parent[p]]) {
                    fl = 1;
                    q.push(parent[p]);
                    vis[parent[p]] = true;
                }
            
                if(p -> left && !vis[p->left]){
                    fl = 1;
                    q.push(p->left);
                    vis[p->left] = true;
                }
                
                if(p-> right && !vis[p->right]){
                    fl = 1;
                    q.push(p->right);
                    vis[p->right] = true;
                }
            }
            
            if(fl) time++;
    }
    
    return time;
    
    }
    
    // Use DFS and find max of all depth
    int minTimeHelper(Node* root, int time, Node* prev, unordered_map<Node*, Node*>& parent){
        if(root == NULL) return time-1;
        
        int p = 0, l = 0, r = 0;
        
        if(parent[root] != prev)
            p = minTimeHelper(parent[root], time+1, root , parent);
        
        if(root-> left!= prev)
            l = minTimeHelper(root -> left, time+1, root, parent);
        
        if(root-> right != prev)
            r = minTimeHelper( root -> right, time+1, root, parent );
        
        return max(p, max(l, r));
        
    }
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;
        Node* targetAdd = NULL;
        findParent(parent, root, NULL, &targetAdd, target);
        return minTimeUsingBfs(targetAdd, parent);
        
    }
};

/***** APPROACH ***
 Time: O(n) both using BFS and DFS
 
 - Make a hashmap to store parent of each node
 - Either use BFS or DFS
    - Using DFS find max depth among parent, left and right child
    - Perform BFS using Queue to find minTime
    
 ******************/